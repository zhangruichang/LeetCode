__author__ = 'richard'
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def isBalanced(self, root):
        h, isBBT=self.B(root)
        return isBBT

    def B(self, root):
        if root is None:
            return 0, True
        lh, Left=self.B(root.left)
        rh, Right=self.B(root.right)
        h=max(lh, rh)+1
        return h, Left and Right and abs(rh-lh)<=1
