#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
using namespace std;





/*
class Solution {
public:
    int kth;
    string kthper;
    int cnt;
    vector<int> vec;
    bool used[10000];
    string getPermutation(int n, int k) {
        kth=k;
        cnt=0;
        vec.clear();
        memset(used,0,sizeof(bool)*n);
        permutation(0,n-1);
        return kthper;
    }
    void permutation(int k, int n)
    {
    if(k>n)
    {
        //for(int i=0;i<vec.size();i++)
        //   cout<<vec[i]<<" ";
        //cout<<endl;
        cnt++;
        if(cnt==kth)
        {
            kthper="";
            for(int i=0;i<vec.size();i++)
                kthper+=char(vec[i]+'0');
        }
    }
    else
    {
        for(int i=0;i<=n;i++)
        {
            if(!used[i])
            {
                vec.push_back(i+1),used[i]=1;
                permutation(k+1,n);
                vec.pop_back(),used[i]=0;
            }
        }
    }
    }
};*/

class Solution
{
public:
    bool used[100000];
    int f(int n)
    {
        int product=1;
        for(int i=n;i>=1;i--) product*=i;
        return product;
    }
    string getPermutation(int n, int k)
    {
        string kthper;
        int cnt;
        memset(used,0,sizeof(bool)*n);
        int jie=f(n-1);
        k--;
        for(int i=1;i<n;i++)
        {
            int curnum=k/jie;
            k=k%jie;
            jie/=(n-i);
            cnt=0;
            for(int i=0;i<n;i++)
            {
                if(!used[i])
                {
                    cnt++;
                    if(cnt==(curnum+1))
                    {
                        kthper+=char(i+1+'0');
                        used[i]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
            if(!used[i])
                kthper+=char(i+1+'0');
        return kthper;
    }
};


int main()
{
    Solution S;
    //for(int i=1;i<=100;i++)
    time_t start=clock();
    //for(int i=1;i<=6;i++)
        cout<<S.getPermutation(9, 199269)<<endl;
    time_t end=clock();
    cout<<end-start<<endl;
    //permutation(0,n-1);
    return 0;
}