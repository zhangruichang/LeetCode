__author__ = 'richard'
class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def threeSum(self, nums):
        ans=[]
        nums.sort()
        #print nums
        n = len(nums)
        #i=0
        for i in range(n):
            if i-1>=0 and nums[i]==nums[i-1]:
                continue
            e1=nums[i]
            j = i+1
            k = n-1
            while j<k:
                #print j, k
                twosum = nums[j]+nums[k]
                if e1 + twosum> 0 or (k+1 < n and nums[k] == nums[k+1]):
                    k=k-1
                elif e1 + twosum<0 or (j-1>=i+1 and nums[j] == nums[j-1]):
                    j=j+1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    j=j+1
                    k=k-1
        return ans

S=Solution()
nums=[-1, 1, 0]
print S.threeSum(nums)