class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* p=head;
        remainhead=p->next->next;//p->next!=NULL, length>=2
        dummy.next=p->next;
        p->next->next=p;
        p->next=swapPairs(remainhead);
        return dummy.next;
    }
};