class Solution {
    //private:
    //    set<char> A ;
    public:
        unordered_set<char> dict;
        int lengthOfLongestSubstring(string s) {
            int n=s.size();
            if(n==0||n==1)
                return n;
            int maxlen=1;
            bool repeated;
            for(int len=1;len<=n;len++)
            {
                for(int i=0;i<=n-1;i++)
                {
                    //string sub=s.substr(i,len);
                    repeated=0;
                    dict.clear();
                    for(int j=i;j<=i+len-1;j++)
                    {
                        if(dict.find(s[j])==dict.end())
                        {
                            dict.insert(s[j]);
                        }
                        else
                        {
                            repeated=1;break;
                        }
                    }
                    if(repeated==0)
                        maxlen=max(maxlen,len);
                }
            }
            return maxlen;
        }
} ;
class Solution {
    public:
        unordered_set<char> dict;
        int lengthOfLongestSubstring(string s) {
            int n=s.size();
            if(n==0 || n==1) return n;
            int maxlen=1;
            for(int st=0;st<=n-1;st++)//start
            {
                dict.clear();
                for(int e=st;e<=n-1;e++)
                {
                    if(dict.find(s[e])==dict.end())
                    {
                        dict.insert(s[e]);
                    }
                    else
                    {
                        maxlen=max(maxlen,e-st);
                        break;
                    }
                }
            }
            return maxlen;
        }
}