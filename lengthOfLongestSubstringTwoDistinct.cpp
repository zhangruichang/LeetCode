class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n=s.size(), ttcnt=0, start=0, maxlen=0, laststart;
        int ch[256];memset(ch, 0, sizeof(ch));
        for(int end=0;end<n;end++)
        {
            if(ttcnt<2)
            {
                if(ch[s[end]] == 0) ttcnt++;
                ch[s[end]]++;
            }
            else
            {
                if(ch[s[end]]==0)
                {
                    maxlen=max(maxlen, end-start);
                    start=laststart;
                    ch[s[start-1]]=0;
                    ch[s[end]]++;
                }
            }
            if(!end || s[end-1] != s[end]) laststart=end;
        }
        maxlen=max(maxlen, n-start);
        return maxlen;
    }
};