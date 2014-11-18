#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dp[1000],min;
    int largestRectangleArea(vector<int> &height) {
        dp[0]=height[0],min=height[0];
        for(int i=1;i<height.size();i++)
        {
            if(height[i]>=min)
            {
                if(dp[i-1]+min>height[i])
                    dp[i]=dp[i-1]+min;
                else
                    dp[i]=height[i],min=height[i];
            }
            else
            {
                dp[i]=height[i]*(i+1),min=height[i];
            }
        }
        for(int i=0;i<height.size();i++)
            cout<<dp[i]<<" ";
        cout<<endl;
        return dp[height.size()-1];
    }
};

int main()
{
    vector<int> height{2,1,5,6,2,3};
    Solution S;
    cout<<S.largestRectangleArea(height)<<endl;
}