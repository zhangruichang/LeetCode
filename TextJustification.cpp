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
    vector<string> fullJustify(vector<string> &words, int L) {
        int len=words.size();
        vector<string> result;
        for(int i=0;i<len;)
        {
            int j,rowlen=0;
            for(j=i;j<len && rowlen+words[j]<=L)
                rowlen+=(words[j++].size()+1);
            if(j-i==1)//one word
            {
                string tmp=words[i];
                AddSpace(tmp, L-words[i].size());
                result.push_back(tmp);
                i=j;
                continue;
            }
            if(j==len)
            {
                string tmp;
                for(int k=i;k<j;k++)
                    tmp+=words[k];
                AddSpace(tmp,L-tmp.size());
                result.push_back(tmp);
                break;
            }
            int charlen=rowlen-(j-i);
            int meanspace=(L-charlen)/(j-i-1);
            int leftmorespace=(L-charlen)%(j-i-1);
            string tmp;
            for(int k=i;k<j-1;k++)
            {
                tmp+=words[k];
                AddSpace(tmp,meanspace+leftmorespace>0 ? 1: 0);
                leftmorespace--;
            }
            result.push_back(tmp);
            i=j;
        }
        return result;
    }
    void AddSpace(string &s, int spacenum)
    {
        for(int i=1;i<=SpaceNum;i++) s.push_back(' ');
    }
} F;

int main()
{
    vector<string> words={"This", "is", "an", "example", "of", "text", "justification."};
    int L=16;
    auto ans=F.fullJustify(words,L);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}