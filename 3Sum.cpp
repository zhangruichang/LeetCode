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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ans;
		if(num.size()<=2) return ans;
		sort(num.begin(),num.end());
		int target,result;
		for(int i=0;i<num.size();i++)
		{
			if(num[i]==num[i-1]) continue;
			for(int j=i+1,j<num.size();j++)
			{
				if(num[j]==num[j-1]) continue;
				target=0-num[i]-num[j];
				result=lower_bound(num+j+1,num.end(),target);
				if(target==result)
				{
					vector<int> onesol{num[i],num[j],target};
					ans.push_back(onesol);
				}
			}
		}
		return ans;
	}
};

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
		if(num.size()<=2) return ans;
		sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++)
        {
            if(i>=1 && num[i]==num[i-1]) continue;
            int target=0-num[i];
            int s=i+1,e=(int)num.size()-1;
            while(s<e)
            {
                if(num[s]+num[e]==target)
                {
                    if(num[s]!=num[s-1]&& s>=i+2)
                    {
                        vector<int> onesol{num[i],num[s],num[e]};
                        ans.push_back(onesol);
                    }
                    s++,e--;
                }
                else if(num[s]+num[e]>target)
                {
                    e--;
                }
                else
                    s++;
                
            }
        }
        return ans;
    }
}

int main()
{
	return 0;
}