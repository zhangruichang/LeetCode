class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m=s.size(), n=t.size();
        if(abs(m-n)>=2) return 0;
        if(m==n)
        {
            int difcnt=0;
            for(int i=0;i<m;i++)
                if(s[i]!=t[i]) difcnt++;
            return difcnt==1;
        }
        if(m<n) return isOneEditDistance(t,s);
        int difcnt=0;
        for(int i=0, j=0; i<m && j<m-1;)
        {
            if(s[i]!=t[j]) i++,difcnt++;
            else i++, j++;
        }
        return difcnt<=1;
    }
};