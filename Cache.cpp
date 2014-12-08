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

struct Node
{
    int key,value;
    Node* prev,*next;
    Node(int key, int value_):key(-1), value(-1),prev(nullptr),next(nullptr)
    {
    }
    void MoveToHead(Node* p)//p is not null
    {
        if(head.next==p) return;
        p->prev->next=p->next;
        //if(p->next)
            p->next->prev=p->prev;
        p->next=head.next;
        //if(head.next)
            head.next->prev=p;
        p->prev=&head;
        head.next=p;
        
    }
    void InsertToHead(Node* p)
    {
        p->next=head.next;
            head.next->prev=p;
        p->prev=&head;
        head.next=p;
    }
};


class LRUCache{
    Node head, tail;
    int len,maxlen;
    unordered_map<int, Node*> keymap;
public:
    LRUCache(int capacity) {
        len=0,maxlen=capacity;
        head.next=&tail;
        tail.prev=&head;
    }
    
    int get(int key) {
        auto it=keymap.find(key);
        if(it!=keymap.end())
        {
            MoveToHead(it->second);
            return (it->second)->value;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        auto it=keymap.find(key);
        if(it!=keymap.end())
        {
            it->second->value=value;
            MoveToHead(it->second);
        }
        else if(len<maxlen)
        {
            Node P(key,value);
            keymap[key]=&P;
            InsertToHead(&P);
            len++;
        }
        else//replace
        {
            Node P(key,value);
            keymap[key]=&P;
            InsertToHead(&P);
            
            keymap.erase(tail.prev->key);
            tail.prev=tail.prev->prev;
            tail->prev->next=&tail;
        }
    }
};