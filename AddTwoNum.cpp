class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //insert head node
        ListNode* head1=l1, *head2=l2;
        l1=new ListNode(0),l2=new ListNode(0);
        l1->next=head1,l2->next=head2;
        ListNode *p1, *p2, *l3=new ListNode(0),*tail3=l3;
        
        p1=head1->next,p2=head2->next;
        int carry=0;
        while(p1 && p2)
        {
            result=p1->val+p2->val+carry;
            if(result>=10)
                tail3->next=new ListNode(result-10),carry=1,tail3=tail3->next;
            else
                tail3->next=new ListNode(result),carry=0,tail3=tail3->next;
            p1=p1->next,p2=p2->next;
        }
        if(!p1 && p2)
        {
            if(p2->val+carry<=9)
            {
                p2->val+=carry;
                tail3->next=p2;
            }
            else
            {
                ListNode* tmp2=p2,tail2;
                while(tmp2&& tmp2->val+carry>=10)
                {
                    tmp2->val+=(carry-10);
                    carry=1;
                    tail2=tmp2;
                    tmp2=tmp2->next;
                }
                if(tmp2!=NULL)
                {
                    tmp2->val+=carry;
                    tail3->next=p2;
                }
                else
                {
                    tail2->next=new ListNode(1);
                    tail3->next=p2;
                }
            }
        }
        else if(p1&& !p2)
        {
            if(p1->val+carry<=9)
            {
                p1->val+=carry;
                tail3->next=p1;
            }
            else
            {
                ListNode* tmp1=p1,tail1;
                while(tmp1&& tmp1->val+carry>=10)
                {
                    tmp1->val+=(carry-10);
                    carry=1;
                    tail1=tmp1;
                    tmp1=tmp1->next;
                }
                if(tmp1!=NULL)
                {
                    tmp1->val+=carry;
                    tail3->next=p1;
                }
                else
                {
                    tail1->next=new ListNode(1);
                    tail3->next=p1;
                }
            }
        }
        else
        {
            if(carry==1)
            {
                tail3->next=new ListNode(1);
            }
        }
        l3=l3->next;
        return l3;
    }
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode  dummy(-1);  //  头节点
        int  carry  =  0, ai, bi ;
        ListNode  *prev  =  &dummy;
        for  (ListNode  *pa  =  l1,  *pb  =  l2; pa  !=  nullptr  ||  pb  !=  nullptr ; )
        {
            if(pa==nullptr)
                ai=0;
            else
                ai=pa->val;
            if(pb==nullptr)
                bi=0;
            else
                bi=pb->val;
            int  value  =  (ai  +  bi  +  carry)  %  10;
            carry  =  (ai  +  bi  +  carry)  /  10;
            prev->next  =  new  ListNode(value);  //  尾插法
            if(pa!=nullptr) 
                pa=pa->next;
            if(pb!=nullptr) 
                pb=pb->next;
            prev  =  prev->next;
        }
        if  (carry  >  0)
            prev->next  =  new  ListNode(carry);
        return  dummy.next;
    }
};