__author__ = 'richard'
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        prev, p=None, head
        #p=head
        while p is not None:
            pnext=p.next
            p.next=prev
            prev=p
            p=pnext
        return prev
    def show(self, head):
        p=head
        while p is not None:
            print p.val,
            p=p.next

S=Solution()
head=ListNode(1)
p1=ListNode(2)
head.next=p1
S.show(head)
head=S.reverseList(head)
print ""
S.show(head)
