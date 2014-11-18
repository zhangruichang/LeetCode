  #include <algorithm>
  #include <vector>
  using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	static bool comp(ListNode* p1, ListNode* p2)
	{
		return p1->val>p2->val;
	}
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		int save=0;
		for(int i=0;i<lists.size();i++)
			if(lists[i]!=nullptr) lists[save++]=lists[i];
		lists.resize(save);
		if(lists.size()==0) return nullptr;
        make_heap(lists.begin(),lists.end(),comp);
		ListNode Dummy(-1);ListNode *p=&Dummy;
		while(lists.size()>1)
		{
			p->next=lists.front();p=p->next;
			lists.front()=lists.front()->next;
			if(lists.front()==nullptr)
				pop_heap(lists.begin(),lists.end(),comp),lists.pop_back();
			else
				pop_heap(lists.begin(),lists.end(),comp),push_heap(lists.begin(),lists.end(),comp);
			
		}
		p->next=lists.front();
		return Dummy.next;
    }
};