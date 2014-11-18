class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode dummy(-1);dummy.next=head;
        ListNode* slow=head, *fast=head;
        if(head==NULL || head->next==NULL) return NULL;
        do
        {
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast && slow!=nullptr && fast !=nullptr && fast->next!=nullptr);
        if(slow==fast && slow!=nullptr)
        {
            ListNode* p=head, *q=slow;
            while(p!=q)
            {
                p=p->next;
                q=q->next;
            }
            return p;
        }
        else 
            return nullptr;
    }
};