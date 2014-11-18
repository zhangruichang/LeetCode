#include <vector>
using namespace std;
class Solution {
public:
    int dp[100+1][100+1];
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    
    
        int m=obstacleGrid.size();
        if(m==0) return 0;
        int n=obstacleGrid[0].size();
        if(n==0) return 0;
        dp[0][0]=1;
        for(int i=0;i<=m-1;i++)
        {
            for(int j=0;j<=n-1;j++)
            {
                
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                if(!i && !j)
                    continue;
                dp[i][j]=0;
                if(i-1>=0)
                    dp[i][j]+=dp[i-1][j];
                if(j-1>=0)
                    dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    return 0;
}