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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, bool> tv;
        for(auto i: dict) {tv[i]=0; if(i==start) tv[i]=1;}
        tv[end]=0;
        
        unordered_set<string> level;
        queue<string> q;
        q.push(start);
        bool endok=0;
        int len=1;
        while(!q.empty())
        {
            int qsize=q.size();
            level.clear();
            for(int i=0;i<qsize;i++)
            {
                auto cur=q.front(); if(cur==end) {endok=1; break;}
                //cout<<cur<<endl;
                q.pop();
                //string tmp=cur;
                for(int j=0;j<cur.size();j++)
                {
                    string tmp=cur;
                    for(char c='a';c<='z';c++)
                    {
                        if(c!=cur[j])
                        {
                            tmp[j]=c;
                            auto it=tv.find(tmp);
                            if(it!=tv.end() && ! (it->second) )
                            {   
                                if(level.find(tmp)==level.end())
                                    level.insert(tmp),q.push(tmp);
                            }
                        }
                    }
                }
            }
            if(endok) break;
            for(auto i: level) tv[i]=1;
            //for(auto i: tv) cout<<i.first<<" "<<i.second<<" ";
            len++;
        }
        if(!endok) return 0;
        //if(len==2 && (dict.find(start)==ditc.end() || dict.find(end)==ditc.end()) ) return 0; 
        return len ;
    }
} F;

int main()
{
    unordered_set<string> dict={"a","b","c"};
    string start="a",end="c";
    //if()
    cout<<F.ladderLength(start, end, dict)<<endl;
    
    
    return 0;
}