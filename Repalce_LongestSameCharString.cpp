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

//"A apple a day keeps the   doctor sway."
//"The apple the day keeps the    doctor away."

string Replace(string words)
{
    string ans;
    //bool inword;
    string word;
    for(int i=0;i<words.size();i++)
    {
        if(words[i]==' ')
        {
            if(word.size()!=0)
            {
                if(word=="a")
                    ans+="the";
                else if(word=="A")
                    ans+="The";
                else
                    ans+=word;
                word.clear();
            }
            ans.push_back(' ');
        }
        else
        {
            word.push_back(words[i]);
        }
    }
    if(word.size()!=0) ans+=words;
    return ans;
}
string MaxLen(string s)
{
    string word;
    int maxlen=1, maxs=0,ss=0;
    for(int i=0;i<s.size();i++)
    {
        if(i>=1 && s[i]!=s[i-1])
        {
            if(maxlen<(int)word.size())
            {
                maxlen=(int)word.size();
                maxs=ss;
            }
            word=s[i];
            ss=i;
        }
        else
        {
            word.push_back(s[i]);
        }
    }
    if(maxlen<(int)word.size())
    {
        maxlen=(int)word.size();
        maxs=ss;
    }
    return s.substr(maxs,maxlen);
}

int main()
{
    string s="0010101111111000001010101000000";
    cout<<MaxLen(s)<<endl;
    return 0;
}
