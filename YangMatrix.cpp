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
#include<climits>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;

struct Node {
    int value;
    int i, j;

    bool operator<(const Node &b) const {
        return value > b.value;
    }
};
int GetKthSmallest(vector<vector<int> > mat, int k)//m*n,  1<=k<=m*n
{
    int m=mat.size();
    if(m<=0) return 0;
    int n=mat[0].size();
    //k=m*n-k+1;
    priority_queue<Node> pq;
    //vector<vector<bool> > visit(m, vector<bool>(n,0));
    set<pair<int, int> > visit;
    pq.push({mat[0][0], 0, 0});
    for(int i=1;i<k;i++)
    {
        auto cur=pq.top();
        pq.pop();
        //auto it=visit.find( make_pair(cur.i+1, cur.j) );
        if( cur.i+1<m && cur.j<n && visit.find( make_pair(cur.i+1, cur.j) )  == visit.end())
        {
            visit.insert({cur.i+1, cur.j});
            //visit[cur.i+1][cur.j]=1;
            pq.push({mat[cur.i+1][cur.j], cur.i+1, cur.j});
        }
        if(cur.i<m && cur.j+1<n && visit.find(make_pair(cur.i+1, cur.j) )==visit.end())
        {
            visit.insert({cur.i, cur.j+1});
            //visit[cur.i][cur.j+1]=1;
            pq.push({mat[cur.i][cur.j+1], cur.i, cur.j+1});
        }
    }
    return pq.top().value;
}

int GetKthSmallest_RowInc(vector<vector<int> > mat, int k)//1<=k<=m*n
{//Time Com: O(klogk)
    priority_queue<Node> pq;
    int m=mat.size(), n=mat[0].size();
    for(int i=0;i<m;i++) pq.push({mat[i][0], i, 0});
    for(int i=1;i<k;i++)
    {
        if(pq.empty()) break;
        auto cur=pq.top();
        if(cur.j+1<n)
            pq.push({mat[cur.i][cur.j+1], cur.i, cur.j+1});
        pq.pop();
    }
    return pq.top().value;
}
int GetOrderYang(vector<vector<int> > mat, int x)
{
    int m=mat.size(), n=mat[0].size(), order=0;
    for(int i=0, j=n-1; i<m && j>=0;)
    {
        if(mat[i][j]>x) j--;
        else
        {
            order+=j+1;
            i++;
        }
    }
    return order+1;//Kth smallest
}

int GetKthSmallest_GetOrder(vector<vector<int> > mat, int k)
{
    int m=mat.size(), n=mat[0].size();
    int low=mat[0][0], high=mat[m-1][n-1], mid;
    while(low<high)
    {
        mid=(low+high)/2;
        int order=GetOrderYang(mat,mid);
        if(order==k) break;
        else if(order>k) high=mid-1;
        else low=mid+1;
    }
    int maxclose=mat[0][0];
    for(int i=0, j=n-1;i<m && j>=0;)
    {
        if(mat[i][j] > mid) j--;
        else if(mat[i][j]<mid)
        {
            maxclose=max(maxclose, mat[i][j]);
        }
        else
            break;
    }
}

int main()
{
    vector<vector<int> > mat={{1,2,4,6,8},{2,3,5,7,9},{4,6,8,9,10},{5,7,8,10,12}};
    int x=5;
    cout<<GetOrderYang(mat, x)<<endl;
	return 0;
}
