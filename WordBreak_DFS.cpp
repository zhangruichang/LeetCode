#include <iostream>
#include <string>
#include <unordered_set>
#include <cstdio>
using namespace std;

class Solution {
public:
    string s1;
    unordered_set<string> dict1;
    
    bool dfs(int starti)
    {
        if(starti>=(int)s1.size())
            return 1;
        for(int i=starti;i<(int)s1.size();i++)
        {
            if(dict1.find(s1.substr(starti,i-starti))!=dict1.end() && dfs(i))
                return 1;
        }
        return 0;
    }
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        s1=s;
        dict1=dict;
        return dfs(0);
    }
};

int main()
{
    string s="leetcode";
    unordered_set<string> dict;//{"leet","code"};
    dict.insert("leet");dict.insert("code");
    Solution S;
    cout<<S.wordBreak(s,dict)<<endl;
    return 0;
}
