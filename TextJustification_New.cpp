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

/*

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.


*/


class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int strslen=words.size();
        vector<string> ans;
        string line;
        int curlinelen, si, curwordslen,linewordsnum,remainspacenum;
        for(int i=0;i<strslen;i=si)
        {
            si=i;
            //curlinelen=0;
            curwordslen=curlinelen=words[si++].size();
            while(si<strslen && curlinelen<=L) curlinelen+= ( words[si].size()+1 ),curwordslen+= words[si++].size() ; // last line
            curwordslen-=words[si-1].size();
            
            if(si==strslen && curlinelen<=L) //last return;
            {
                line="";
                for(int j=i;j<strslen;j++) line+=words[j];
                for(int j=L;j>line.size();j--) line+=' ';
                ans.push_back(line);
                break;
            }
            cout<<L<<" "<<curlinelen<<endl;
            linewordsnum=si-i-1;remainspacenum=L-curwordslen;
            vector<string> spacenum(linewordsnum-1," "); remainspacenum-=(linewordsnum-1);
            
            int spacei=0;
            while(remainspacenum>0) spacenum[spacei]+=' ', spacei=(spacei+1)%(linewordsnum-1), remainspacenum--; 
            
            
            si=i;
            line=words[si++]; 
            for(int j=0;j<spacenum.size();j++)
            {
                line+=spacenum[j];
                line+= words[si++];
            }
            ans.push_back(line);
        }
        return ans;
    }
} F;

int main()
{
    vector<string> words={"My","momma","always","said,","Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."};
    int L=12;
    auto ans=F.fullJustify(words,L);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}