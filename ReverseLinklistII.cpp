  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode* headnext=head;
		head=new ListNode(0);
		head->next=headnext;
		m++,n++;



		int cnt=1;
		ListNode* p=head, *pre, *reversepre, *reversehead,*pnext;
		while(p && cnt<m)
			reversepre=p,p=p->next,cnt++;
        pre=p,reversehead=p,p=p->next;
		
		//pre=NULL;
		//pnext=p->next;
		while(cnt<n)
		{
			pnext=p->next;
			p->next=pre;
			pre=p;
			p=pnext;
			cnt++;
		}
		reversepre->next=pre;
		reversehead->next=p;

		head=head->next;
		return head;
	}
    void Show(ListNode* head)
    {
        ListNode* p=head;
        while(p)
            cout<<p->val,p=p->next;
    }
    ListNode* Create(int a[], int n)
    {
        if(n<1)
            return NULL;
        ListNode* head=new ListNode(a[0]);
        ListNode* tail=head;
        int i=1;
        while(i<n)
        {
            tail->next=new ListNode(a[i]);
            tail=tail->next;
            i++;
        }
        return head;
    }
};

int main()
{
    Solution S;
    int a[]={3,5},m=2,n=2;
    ListNode* head=S.Create(a,sizeof(a)/sizeof(int));
    S.Show(head);
    head=S.reverseBetween(head,m,n);
    S.Show(head);
    return 0;
}

