class Solution {
public:
    bool isrange()
    {
        
    }
    string longestCommonPrefix(vector<string> &strs) {
        int n=strs.size();
        vector<int> pos{n,0};
        string prefix;
        while(!inrange())
        {
            bool same=true;
            char tmp=strs[0][pos[0]];
            for(int i=1;i<n;i++)
            {
                if(strs[i][pos[i]]==tmp)
                    ;
                else
                {
                    same=false;
                    break;
                }
            }
            if(same==false)
            {
                break;
            }
            else
            {
                prefix.push_back(tmp);
            }
        }
        return prefix;
    }
}