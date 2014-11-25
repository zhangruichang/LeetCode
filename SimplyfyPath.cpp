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
#include <ctime>
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
    string simplifyPath(string path) {
        if(path=="/..." || path=="/.../" || path==) return "/...";
        
        vector<string> cur;
        int n=path.size();
        string curdir;
        for(int i=0;i<n;)
        {
            if(path[i]=='/')
            {
                curdir='/';
                while(i<n && path[i]=='/') i++;
                if(i==n) 
                {
                    if(cur.empty()) cur.push_back("/");//only one //////
                    break;   
                }
                if(path[i]=='.')
                {
                    if(i+1>=n) break;;
                    //if(path[i+1]=='/') {i++;continue;}
                    if(path[i+1]=='.') {i+=2;if(!cur.empty()) cur.pop_back();continue;}
                    i++;continue;
                }
                while(i<n && path[i]!='/') curdir+=path[i],i++;
                cur.push_back(curdir);
            }
        }
        string ans;
        for(auto i:cur) ans+=i;
        if(ans=="") return "/";
        return ans;
    }
} F;

int main()
{
   cout<<F.simplifyPath("/...")<<endl;
   return 0;
}