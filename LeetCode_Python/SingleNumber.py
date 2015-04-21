__author__ = 'richard'
class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        ans=0;
        for i in A:
            ans^=i
        return ans

S=Solution()
A=[0,1,2,2,3,3,0]
print S.singleNumber(A)
