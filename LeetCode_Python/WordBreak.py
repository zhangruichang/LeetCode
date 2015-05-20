__author__ = 'richard'
class Solution:
    # @param s, a string
    # @param wordDict, a set<string>
    # @return a boolean
    def wordBreak(self, s, wordDict):
        n=len(s)
        if n== 0:
            return False
        dp=[False]*(n+1)
        dp[0]=True
        for i in range(1, n+1):
            for j in range(0, i):
                if dp[j] and (s[j:i] in wordDict):
                    #print s[j: i]
                    dp[i]=True
                    break
        #print dp
        return dp[n]

S=Solution()
s='leetcode'
wordDict=['leet', 'code']
print s
print wordDict
print S.wordBreak(s, wordDict)
