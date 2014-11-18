class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode dummy(-1);dummy.next=head;
        ListNode* slow=dummy.next, *fast=dummy.next;
        if(head==NULL) return 0;
        if(head->next==NULL) return 0;
        do//length >=2
        {
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast && slow !=nullptr && fast !=nullptr && fast ->next!=nullptr);
        if(slow==fast && slow!=nullptr)
            return 1;
        else
            return 0;
    }
};