#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int dp[1000][1000];
    int minPathSum(vector<vector<int> > &grid) {
        int m=grid.size();if(m<=0) return 0;
        int n=grid[0].size();
        memset(dp, 0, sizeof(dp));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++) dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int j=1;j<n;j++) dp[0][j]=dp[0][j-1]+grid[0][j];
        for(int i=1;i<m;i++) for(int j=1;j<n;j++)
            dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution S;
    //vector<int> grid1{1,2,3};
    //vector<int> grid2{3,4,5};
    vector<vector<int> > grid{{1,2,3},{3,4,5}};
    //grid.push_back(grid1);
    //grid.push_back(grid2);
    cout<<S.minPathSum(grid)<<endl;
    return  0;
}