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

class MinStack {
private:
    stack<int> data, minx;
public:
    void push(int x) {
        data.push(x);
        if(minx.empty())
            minx.push(x);
        else
            if(x<=minx.top())
                minx.push(x);
    }

    void pop() {
        if(!data.empty())
        {   
            if(!minx.empty() && data.top()== minx.top())
                minx.pop();
            data.pop();
        }
    }

    int top() {
        if(data.empty()) return 0;
        return data.top();
    }

    int getMin() {
        if(minx.empty()) return 0;
        return minx.top();
    }
};


int main()
{
	return 0;
}