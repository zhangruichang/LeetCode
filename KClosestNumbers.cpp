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
    int val;
    int index;
    Node(int val_, int index_):val(val_), index(index_)
    {
    }
    bool operator<(const Node& n1) const
    {
        return val>n1.val;
    }
};

int Partition_InOrder(vector<pair<int, int>> &a, int low, int high)
{//inorder
    int i=low, j=high;
    pair<int,int> pivot=a[low];
    while(i<j)
    {
        while(i<j && a[j].first >= pivot.first) j--;
        while(i<j && a[i].first <= pivot.first) i++;
        if(i<j) swap(a[i], a[j]);
    }
    swap(a[i], a[low]);
    return i;
}

int QuickSelect(vector<pair<int, int> >& a, int low, int high, int k)//select kth smallest, or inorder kth ele
{// 1<=k<=high-low+1, low<=high
    if(low>high) return -1;
    int mid=Partition_InOrder(a, low, high);
    int prelen=mid-low+1;
    if(prelen==k) return a[mid].first;
    else if(prelen > k)
        return QuickSelect(a, low, mid-1, k);
    else
        return QuickSelect(a, mid+1, high, k-prelen);
}

vector<int> FindKClosest_QuickSelect(vector<int>& a, int k, int x)
{
    int n=a.size();
    if(k==n) return a;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++) v.push_back({abs(a[i]-x), i});
    QuickSelect(v, 0, n-1, k+1);
    vector<int> ans;
    for(int i=0;i<k;i++)
        ans.push_back(a[v[i].second]);
    //vector<int> ans(a.begin(), a.begin()+k-1);
    return ans;
}

vector<int> FindKClosest_Heap(vector<int> a, int k, int x)//, 0<=k<=a.size(), O(n+klogn)
{
    //for(auto &i: a) i=abs(i-x);
    vector<Node> v;
    for(int i=0;i<a.size();i++)
    {
        Node n({abs(a[i]-x), i});
        v.push_back(n);
    }
    priority_queue<Node> pq(v.begin(), v.end());
    //for(auto i: v) pq.push(i);
    vector<int> ans;
    //cout<<k<<endl;
    for(int i=0;i<k;i++)
    {
        ans.push_back(a[pq.top().index]);
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<int> a={12,124,53,4,436,6,325,2,253,46,325,32,34};
    int k=5;
    int x=30;
    auto ans=FindKClosest_QuickSelect(a, k, x);
    for(auto i: ans) cout<<i<<" ";
    cout<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
