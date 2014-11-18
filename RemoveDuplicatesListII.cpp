class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode Dummy(-1);
        Dummy.next=head;
        ListNode *pre=&Dummy, *p=head;
        while(p)
        {
            if(p->next==NULL)
                break;
            if(p->val==p->next->val)
            {
                while(p->next!=NULL && p->val==p->next->val)
                    p=p->next;
                pre->next=p->next;
                p=p->next;
            }
            else
            {
                pre=p;p=p->next;
            }
        }
        return Dummy.next;
    }
};