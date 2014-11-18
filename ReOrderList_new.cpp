#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        //ListNode Dummy(-1);Dummy.next=head;
        if(!head) return;
        int len=0;ListNode *p=head, *pre,*pnext;
        while(p) len++,p=p->next;
        int k=0;p=head;
        while(k<(len+1)/2) k++,pre=p,p=p->next;
        pre->next=nullptr;pre=nullptr;
        while(p)
        {
            pnext=p->next;
            p->next=pre;
            pre=p;p=pnext;
        }
        p=head;ListNode* q=pre,*qnext=q;pnext=p;
        while(qnext)
        {
            pnext=p->next;qnext=q->next;
            p->next=q;q->next=pnext;
            p=pnext,q=qnext;
        }
    }
};