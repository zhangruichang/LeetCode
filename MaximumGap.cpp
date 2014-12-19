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
#include <climits>
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

struct bucket
{
    int maxe, mine;
    int elenum;
    bucket(): maxe(0), mine(INT_MAX), elenum(0)
    {
    }
};

const int cntnum=100000;
int cnt[cntnum];

class Solution {
public:

    int maximumGap_countingsort(vector<int> &num) {
        if(num.size()<2) return 0;
        int n=num.size(),curdiff=INT_MIN;
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++)
            cnt[num[i]]=1;
        int lasti=-1;
        for(int i=0;i<=cntnum;i++)
        {
            if(cnt[i])
            {
                if(lasti==-1)
                    lasti=i;
                else
                {
                    curdiff=max(curdiff, i-lasti);
                    lasti=i;
                }
            }
        }
        return curdiff;
    }

    void radixsort(vector<int> &num)
    {
        int dignum=10;//2147483647
        int bucket[10];
        int n=num.size();
        vector<pair<int, int> > num1, num2;
        for(auto i:num) num1.push_back({i,i});
        num2=num1;
        for(int i=0;i<dignum;i++)
        {
            memset(bucket, 0, sizeof(bucket));
            for(int j=0;j<n;j++)
                bucket[num1[j].first%10]++;
            for(int j=1;j<10;j++)
                bucket[j]+=bucket[j-1];
            for(int j=n-1;j>=0;j--)
            {
                num2[bucket[num1[j].first%10]-1]=num1[j];
                bucket[num1[j].first%10]--;
            }
            for(auto &i:num2) i.first/=10;
            num1=num2;
        }
        for(int i=0;i<n;i++) num[i]=num1[i].second;
    }
    void Show(vector<int> num)
    {
        for(auto i: num) cout<<i<<" ";
        cout<<endl;
    }
    int maximumGap_radixsort(vector<int> &num) {
        int n=num.size();if(n<2) return 0;
        radixsort(num);
        int maxgap=0;
        for(int i=0;i<n-1;i++)
            maxgap=max(maxgap, num[i+1]-num[i]);
        return maxgap;
    }

    int maximumGap_pifeonhole(vector<int> &num) {
        int n=num.size();
        int maxe=*max_element(num.begin(),num.end());
        int mine=*min_element(num.begin(),num.end());
        double bucketsize=double(maxe-mine)/(n-1);
        bucket data[n-1];
        for(auto i:num)
        {
            int bucketid= i!=maxe ? (i-mine)/bucketsize: n-2;
            data[bucketid].maxe=max(data[bucketid].maxe, i);
            data[bucketid].mine=min(data[bucketid].mine, i);
            data[bucketid].elenum++;
        }
        int save=0;
        for(int i=0;i<n-1;i++)
            if(data[i].elenum)
                data[save++]=data[i];
        int maxgap=0;
        for(int i=0;i<save-1;i++)
            maxgap=max(data[i+1].mine-data[i].maxe,maxgap);
        return maxgap;
    }
} F;

int main()
{
    //vector<int> num={15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};

    vector<int> num={1,22,3,4,5,9,14};
    cout<<F.maximumGap(num)<<endl;
    //F.Show(num);
	return 0;
}