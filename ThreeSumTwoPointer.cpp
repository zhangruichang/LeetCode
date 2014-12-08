#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))


class Solution {
public:
    vector<vector<int> > threeSum_hash(vector<int> &num)
    {
        int n=num.size();
        vector<vector<int> > ans;

        unordered_multimap<int, pair<int,int> > table;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        table.insert(  {num[i]+num[j],{i,j} });
        for(int i=0;i<n;i++)
        {
            int remain=-num[i];
            auto itrange=table.equal_range(remain);
            for(auto it=itrange.first;it!=itrange.second;it++)
            {

                int index1=it->second.first,index2=it->second.second;
                if(it->second.first!=i && it->second.second!=i)
                {
                    vector<int> row={num[i],num[index1],num[index2]};
                    sort(row.begin(),row.end());
                    ans.push_back(row);
                }
            }
        }
        return ans;
    }

    vector<vector<int> > threeSum(vector<int> &num)
    {
        int n=num.size();
        vector<vector<int> > ans;
        sort(num.begin(),num.end());
        for(int i=0;i<n;i++)
        {
            if(i!=0 && num[i]==num[i-1]) continue;
            for(int j=i+1,k=n-1;j<k;)
            {
                if(num[j]+num[k] + num[i] > 0 || (num[k+1]==num[k] && k+1<n) )
                    k--;
                else if(num[j]+num[k] + num[i] < 0 || ( num[j]==num[j-1] && j-1>=i+1) )
                    j++;
                else
                {
                    vector<int> oneans={num[i],num[j],num[k]};
                    ans.push_back(oneans);
                    j++,k--;
                }
            }
        }
        return ans;
    }

} F;
int main()
{
    vector<int> num={-1,0, 1, 2, -1, -4};
    auto ans=F.threeSum(num);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
