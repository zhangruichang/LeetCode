#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2 ;
        if (l2 == NULL) return l1 ;
        int c = (l1->val + l2->val) / 10 ;
        l1->val = (l1->val + l2->val) % 10 ;
        if ( c ) {
            if ( l1->next == NULL ) l1->next = new ListNode(c) ;
            else if ( l2->next == NULL ) l2->next = new ListNode(c) ;
            else l1->next->val += c;
        }
        l1->next = addTwoNumbers(l1->next , l2->next) ;
        return l1 ;
    }
};
int main()
{
}