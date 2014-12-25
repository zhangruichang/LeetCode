#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
//time: O(Nlgk), space: O(k)
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val_):val(val_), next(nullptr)
    {
    }
};
typedef bool(*comp)(ListNode*, ListNode*);

class Inter{
public:
    static bool compare(ListNode* p1, ListNode* p2)
    {
        return p1->val>p2->val;//> minheap
    }
    static bool compare2(ListNode* p1, ListNode* p2)
    {
        return p1->val<p2->val;//> maxvalue;
    }
    ListNode* Intersection(vector<ListNode*> lists)
    {
        int save=remove(lists.begin(),lists.end(), nullptr)-lists.begin();
        lists.resize(save);
        priority_queue<ListNode*, vector<ListNode*>, comp> pq(lists.begin(), lists.end(), compare);
        int maxvalue=(*max_element(lists.begin(),lists.end(),compare2))->val;
        ListNode Dummy(-1);ListNode* tail=&Dummy;
        while(!pq.empty())
        {
            if(pq.top()->val==maxvalue)
            {
                tail->next=new ListNode(maxvalue);
                cout<<maxvalue<<endl;
                tail=tail->next;
                while(!pq.empty()) pq.pop();
                bool end=0;
                for(auto &i:lists)
                {
                    if(i->next)
                        i=i->next;
                    else
                    {
                        end=1;
                        break;
                    }
                }
                if(end) break;
                for(auto i:lists) pq.push(i);
                //priority_queue<ListNode*, vector<ListNode*>, comp> pq2(lists.begin(),lists.end(),compare);
                //pq=pq2;
                maxvalue=(*max_element(lists.begin(),lists.end(),compare2))->val;
            }
            else
            {
                ListNode* tmp=pq.top()->next;
                pq.pop();
                if(tmp)
                {
                    pq.push(tmp);
                    maxvalue=max(maxvalue, tmp->val);
                }
                else
                    break;
            }
        }
        return Dummy.next;
    }

    ListNode* Create(int a[], int n)
    {
        if(n<=0) return nullptr;
        ListNode* head=new ListNode(a[0]), *tail=head;
        for(int i=1;i<n;i++)
        {
            tail->next=new ListNode(a[i]);
            tail=tail->next;
        }
        return head;
    }
    void Show(ListNode* head)
    {
        for(ListNode* p=head; p; p=p->next)
            cout<<p->val<<" ";
        cout<<endl;
    }
} F;
int main()
{
    int a[]={1,4,7,8,10};
    int b[]={2,3,5,8,11};
    int an=sizeof(a)/sizeof(int);
    int bn=sizeof(b)/sizeof(int);
    ListNode* list1=F.Create(a,an);
    ListNode* list2=F.Create(b,bn);
    F.Show(list1);F.Show(list2);
    vector<ListNode*> lists={list1,list2};
    auto listall=F.Intersection(lists);
    F.Show(listall);
    //cout << "Hello world!" << endl;
    return 0;
}
