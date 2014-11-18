  struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode Dummy(-1);Dummy.next=head;
		
		ListNode* p=head,*pre=&Dummy;
		//if(p==nullptr) return nullptr;
		bool hasduplicate=0;
		while(p)
		{
			if(p->next==nullptr)
			{
				if(hasduplicate)
					pre->next=p->next;
				break;
			}
			if(p->val==p->next->val)
			{
				hasduplicate=1;
				p=p->next;
			}
			else
			{
				if(!hasduplicate)
					pre=p,p=p->next;
				else
					hasduplicate=0,pre->next=p->next,p=p->next;
			}
		}
		
		return Dummy.next;
	}
};