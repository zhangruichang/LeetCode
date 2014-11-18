#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> greyint;
        if(n==0)
        {
            greyint.push_back(0);
            return  greyint;
        }
        if(n==1)
        {
            greyint.push_back(0);
            greyint.push_back(1);
            return greyint;
        }
        //vector<int> p0{0,0}, p1{1,0},p2{1,1},p3{0,1};
        vector<vector<int> > curgrey{{0,0},{1,0},{1,1},{0,1}};
        vector<vector<int> >nextgrey;
        vector<int> tmp;
        for(int num=0;num<n-2;num++)
        {
            nextgrey.clear();
            for(int i=0;i<curgrey.size();i++)
            {
                tmp=curgrey[i];
                tmp.push_back(0);
                nextgrey.push_back(tmp);
            }
            for(int i=(int)curgrey.size()-1;i>=0;i--)
            {
                tmp=curgrey[i];
                tmp.push_back(1);
                nextgrey.push_back(tmp);
            }
            curgrey=nextgrey;
        }
        greyint.clear();
        for(int i=0;i<(int)curgrey.size();i++)
        {
            int num=0;
            for(int j=0;j<(int)curgrey[i].size();j++)
                num+=curgrey[i][j]*pow(2.0, j);
            greyint.push_back(num);
        }
        return greyint;
    }
};

int main()
{
    Solution S;
    for(int n=0;n<=6;n++)
    {
        vector<int> grey=S.grayCode(n);
        for(int i=0;i<grey.size();i++)
            cout<<grey[i]<<" ";
        cout<<endl;
    }        
    return 0;
}