class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode Dummy(-1),Dummy.next=head;
        ListNode* p=head,* pre,*pnext;
        int cnt=0;
        while(p && cnt<k)
            cnt++,p=p->next;
        if(cnt<k)  return Dummy.next;
        cnt=0;p=head;
        while(cnt<k)
        {
            pnext=p->next;
            p->next=pre;
            pre=p,p=pnext;cnt++;
        }
        Dummy.next=pre;
        head->next=reverseKGroup(p,k);
        return Dummy.next;
    }
};