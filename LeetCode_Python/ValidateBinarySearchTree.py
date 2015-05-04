__author__ = 'richard'
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import sys
class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def isValidBST(self, root):
        maxx=sys.maxint
        minx=-maxx-1
        print maxx, minx
        return self.isBST(root, minx, maxx)
    def isBST(self, root, minx, maxx):
        if not root:
            return
        leftBST = self.isBST(root.left, leftmin, leftmax)
        rightBST = self.isBST(root.right, rightmin, rightmax)
        minx=min(root.val, min(leftmin, leftmax))
        maxx=max(root.val, max(rightmin, rightmax))
        return leftBST and rightBST and (not root.left or leftmax<root.val) and (not root.right or root.val<rightmin)
S=Solution()
root=None
S.isValidBST(root)