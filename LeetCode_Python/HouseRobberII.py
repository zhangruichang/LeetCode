__author__ = 'richard'

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def robI(self, nums):
        n=len(nums)
        dp=[0]*(n+1)
        for i in range(1, n+1):
            dp[i]=max(dp[i-1], (dp[i-2] if i>=2 else 0) +nums[i-1])
        return dp[n]
    def rob(self, nums):
        if len(nums)==0:
            return 0
        if len(nums)==1:
            return nums[0]
        v1, v2=nums[0:len(nums)-1], nums[1:]
        #print v1, v2
        return max(self.robI(v1), self.robI(v2))

S=Solution()
nums=[1,2,3]
print S.rob(nums)