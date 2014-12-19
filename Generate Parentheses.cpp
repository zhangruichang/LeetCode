struct node
{
    string x;
    int left,right;
    int type;
};
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        stack<node> s;
        vector<string> ans;
        s.push({"",0,0,0});
        while(!s.empty())
        {
            auto& cur=s.top();
            if(cur.left+cur.right==2*n)
            {
                ans.push_back(cur.x);
                s.pop();
            }
            else
            {   if(cur.type==0)
                {
                    cur.type++;
                    if(cur.left<n)
                        s.push({cur.x+'(',cur.left+1, cur.right,0});
                }
                else if(cur.type==1)
                {
                    cur.type++;
                    if(cur.left>cur.right)
                        s.push({cur.x+')',cur.left, cur.right+1,0});
                }
                else
                    s.pop();
            }
        }
        return ans;
    }
};