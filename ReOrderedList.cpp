class Solution {
{
public:
    ListNode* Solve(ListNode* head)
    {
        if(head==NULL || head->next==NULL) return NULL;//length <=1
        ListNode Dummy(-1);Dummy.next=head;
        ListNode* p=head, *pre=&Dummy;
        while(p->next)
            pre=p,p=p->next;
        pre->next=NULL;
        p->next=reorderList(head->next);
        head->next=p;
        return Dummy.next;
    }
    void reorderList(ListNode *head)
    {
        head=Solve(head);
    }
};

class Solution