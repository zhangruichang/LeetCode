__author__ = 'richard'

class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        mydict=set()
        for i in nums:
            if i in mydict:
                return True
            mydict.add(i)
        return False

S=Solution()
nums=[1,2,2,3]
print S.containsDuplicate(nums)