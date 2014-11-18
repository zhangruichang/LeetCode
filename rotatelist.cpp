#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x){}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==nullptr || head->next==nullptr || k==0) return head;
        ListNode Dummy(-1);Dummy.next=head;
        ListNode*p=head, *q=head;
        int cnt=0;
        while(cnt<k) q=q->next,cnt++;
        if(q==nullptr) return head;
        while(q->next!=nullptr) p=p->next,q=q->next;
        
        q->next=head;
        p->next=nullptr;
        Dummy.next=p->next;
        
        return Dummy.next;
    }
};