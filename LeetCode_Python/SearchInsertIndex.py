__author__ = 'richard'
class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        for i,val in enumerate(A):
            if(target<=val):
                return i
        return len(A)