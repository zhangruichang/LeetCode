#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
    private:
        bool pan ;
        ListNode *L ;
    public:
        void Solve(ListNode *R) {
            if (R->next != NULL) Solve(R->next) ;
            if (pan) ;
            else if (L == R || L->next == R) {
                pan = true ;
                R->next = NULL ;
            } else {
                R->next = L->next ; L->next = R ; L = (L->next)->next ;
            }
        }
        void reorderList(ListNode *head) {
            L = head ;
            pan = false ;
            if (head != NULL) Solve(head) ;
        }
} F ;
int main() {
}