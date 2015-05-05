__author__ = 'richard'
class Solution:
    # @param {string} s
    # @return {integer}
    def numDecodings(self, s):
        n=len(s)
        if n==0:
            return 0
        dp=[0]*(n+1)
        dp[0]=1
        for i in xrange(1, n+1):
            dp[i]=0
            if s[i-1]>'0':
                dp[i]+=dp[i-1]
            if i>=2 and (s[i-2]=='1' or s[i-2]=='2' and s[i-1]<='6'):
                dp[i]+=dp[i-2]
        return dp[n]
S=Solution()
s='26'
print S.numDecodings(s)