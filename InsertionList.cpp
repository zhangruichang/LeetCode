#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if(!head || !(head->next) ) return head;
		ListNode Dummy(-1);Dummy.next=head;
		ListNode* pprev=head,*q, *pnext;
		for(ListNode* p=head->next;p;p=pnext)
		{
			pnext=p->next;
			ListNode* qprev=&Dummy;
			for(q=Dummy.next;q!=p && q->val<=p->val ;qprev=q,q=q->next) 
				;
			if(q!=p)
			{
				pprev->next=p->next;
				p->next=q;
				qprev->next=p;
			}
			else
				pprev=p;
		}
		return Dummy.next;
	}
	void Show(ListNode* head)
	{
		while(head)
		{
			cout<<head->val<<" ";
			head=head->next;
		}
		cout<<endl;
	}
	ListNode* Create(int a[], int n)
	{
		ListNode* tail, *head;
		if(n<=0) return nullptr;
		head=new ListNode(a[0]);
		tail=head;
		for(int i=1;i<n;i++)
		{
			ListNode* tmp=new ListNode(a[i]);
			tail->next=tmp;
			tail=tail->next;
		}
		return head;
	}
} F;


int main()
{
	int a[]={4,19,14,5,-3,1,8,5,11,15};
	int n=sizeof(a)/sizeof(int);
	ListNode* head=F.Create(a, n);
	F.Show(head);
	head=F.insertionSortList(head);
	F.Show(head);
	//cout << "Hello world!" << endl;
	return 0;
}
