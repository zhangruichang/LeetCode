__author__ = 'richard'
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        p=Dummy=ListNode(-1)
        c=0
        while l1 is not None or l2 is not None or c != 0:
            sum=c
            if l1 is not None:
                sum=sum+l1.val
                l1=l1.next
            if l2 is not None:
                sum=sum+l2.val
                l2=l2.next
            p.next=ListNode(sum%10)
            p, c=p.next, sum/10
        return Dummy.next

