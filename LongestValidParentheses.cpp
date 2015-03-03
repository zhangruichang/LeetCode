int dp[30000];
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(); if(n<=1) return 0;
        memset(dp, 0, sizeof(dp));
        int maxlen=0;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]==')') 
            {
                int id = i - 2 - dp[i - 1];
                if(id >= 0 && s[id]=='(') dp[i] = dp[i - 1] + 2 + dp[id];
            }
            maxlen=max(maxlen, dp[i]);
        }
        return maxlen;
    }
};