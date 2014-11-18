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
    vector<string> map={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string cur,_digits;
    int n;
    vector<string> letterCombinations(string digits) {
        n=digits.size();_digits=digits;
        ans.clear();cur="";
        if(n==0) return ans;
        dfs(0);
        return ans;
    }
    void dfs(int i)
    {
        if(i>=n)
            ans.push_back(cur);
        else
        {
            for(int j=0;j<map[_digits[i]-2-'0'].size();j++)
                cur.push_back(map[_digits[i]-2-'0'][j]),dfs(i+1),cur.pop_back();
        }
    }
    
} F;

int main()
{
    auto ans=F.letterCombinations("534675734");
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    puts("");
    return 0;
}