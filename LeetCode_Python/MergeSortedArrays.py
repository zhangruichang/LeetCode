__author__ = 'richard'
class Solution:
    # @param {integer[]} nums1
    # @param {integer} m
    # @param {integer[]} nums2
    # @param {integer} n
    # @return {void} Do not return anything, modify nums1 in-place instead.
    def merge(self, nums1, m, nums2, n):
        i, j, k=m-1, n-1,m+n-1
        while i>=0 and j>=0:
            if nums1[i]>nums2[j]:
                nums1[k]=nums1[i]
                i-=1
            else:
                nums1[k]=nums2[j]
                j-=1
            k-=1
        if j>=0:
            for jj in range(j, -1, -1):
                nums1[k]=nums2[jj]
                k-=1



S=Solution()
num1=[0]
m=0
num2=[1]
n=1
S.merge(num1, m, num2, n)
print num1
