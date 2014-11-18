#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        int st=0, e=1,len=(int)s.size(),maxlen=1;
        if(len==0) return 0;
        unordered_map<char, int> curstr;
        curstr[s[st]]=st;
        while(e<len)
        {
            auto ite=curstr.find(s[e]);
            if(ite==curstr.end())
                curstr[s[e]]=e,e++;
            else
            {
                maxlen=max(maxlen,e-st);
                st=ite->second+1;
                e++;
                curstr.clear();
                for(int i=st;i<=e-1;i++)
                    curstr[s[i]]=i;
                //s++;
                //e++;
                
                //for(int i=s;i<=e-1;i++)
                //    curstr.insert(s[i]);
                
            }
        }
        maxlen=max(maxlen,e-st);
        return maxlen;
    }
};

int main()
{
    freopen("LongestPalindromeString_in.txt","r",stdin);
    string s,total;
    Solution S;
    while(cin>>s)
        total+=s;
    time_t start=clock();
    cout<<S.lengthOfLongestSubstring(total)<<endl;
    time_t end=clock();
    cout<<end-start<<endl;
    return 0;
}