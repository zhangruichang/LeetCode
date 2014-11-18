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

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n/2;j++)
                swap(matrix[i][j],matrix[i][n-1-j]);
    }
};

int main()
{
	return 0;
}