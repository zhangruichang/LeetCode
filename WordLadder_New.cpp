//mistakes
//1. add start and end into visit, set 1 and 0 separately
//2. as maybe not found the path, set bool found to check whether can find such path
//3. queue must set visit in in push step in graph (tree do not need set push in bfs code), 
//4. found should be jump out the loop, two level loops carefully, use goto, and final return according to found value
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, bool> table;
        for(auto i: dict) table[i]=0;
        table[end]=0;//table[start]=1;
        queue<string> q;
        q.push(start);
        int len=1; bool found=0;
        while(!q.empty())
        {
            int qsize=q.size();
            for(int i=0;i<qsize;i++)
            {
                auto cur=q.front();q.pop();
                if(cur==end) 
                {
                    found=1;
                    goto L1;
                }
                for(int i=0;i<cur.size();i++)
                {
                    string tmp=cur;
                    for(char ch='a';ch<='z';ch++)
                    {
                        if(ch==cur[i]) continue;
                        tmp[i]=ch;
                        auto it=table.find(tmp);
                        if(it!=table.end() && !it->second)
                            q.push(tmp), it->second=1;
                    }
                }
            }
            len++;
        }
L1:     return found ? len : 0;
    }
};