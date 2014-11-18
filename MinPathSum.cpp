#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int dp[500][500];
    int minPathSum(vector<vector<int> > &grid) {
        //m rows, n cols
        int m=grid.size();
        if(m<=0)
            return 0;
        int n=grid[0].size();
        if(n<=0)
            return 0;
    
        dp[0][0]=grid[0][0];
        
        
        for(int j=1;j<=n-1;j++)
            dp[0][j]=dp[0][j-1]+grid[0][j];
        for(int i=1;i<=m-1;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int i=1;i<=m-1;i++)
        {
            for(int j=1;j<=n-1;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        /*
        for(int i=0;i<=m-1;i++)
        {    for(int j=0;j<=n-1;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
            }*/
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