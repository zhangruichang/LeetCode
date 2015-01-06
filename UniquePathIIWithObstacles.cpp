class Solution {
public:
    int dp[1000][1000];
    int uniquePathsWithObstacles(vector<vector<int> > &A) {
        int m=A.size(); if(m<=0) return 0;
        int n=A[0].size();
        memset(dp, 0 ,sizeof(dp));
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        {
            if(!i && !j && !A[i][j]) { dp[0][0]=1; continue; }//corner case
            if(A[i][j]) continue;//obstable
            if(i>=1)
                dp[i][j]+=dp[i-1][j];
            if(j>=1)
                dp[i][j]+=dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};