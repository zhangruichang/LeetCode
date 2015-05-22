__author__ = 'richard'


class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        n=len(nums)
        dp=[0]*(n+1)
        for i in range(1, n+1):
            dp[i]=max(dp[i-1], (dp[i-2] if i>=2 else 0) +nums[i-1])
        return dp[n]

S=Solution()
nums=[]
print S.rob(nums)

