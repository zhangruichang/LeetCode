//mistakes:
//level should be no duplicate strings, so must be hashset, not vector
//must add end to visit hashmap, and set 0, and add start to visit, set 1
//as CPP STL queue front() and pop() are separated, so do not forget to use pop()
//dfs get path, carefully process start and end string, can first push start, or last push end separately
class Solution {
public:
    unordered_map<string, vector<string> > graph;//graph of distance 1 edge betweem strings in dict, and start, end
    string start_, end_;//global variables
    vector<vector<string>> ans; // ans
    vector<string> cur; //cur path
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, bool> visit;//visit tags
        graph.clear();
        start_=start, end_=end;
        for(auto i: dict) visit[i]=0;
        visit[start]=1;visit[end]=0;
        queue<string> q;
        q.push(start);
        while(!q.empty())
        {
            int qsize=q.size();
            unordered_set<string> level;//remove duplicates in one level, as it's not bfs in a tree structure, but a DAG
            for(int i=0;i<qsize;i++)
            {
                auto cur=q.front();q.pop();
                for(int j=0;j<cur.size();j++)
                {
                    string tmp=cur;
                    for(char ch='a';ch<='z';ch++)
                    {
                        if(ch==cur[j]) continue;
                        tmp[j]=ch;
                        auto it=visit.find(tmp);
                        if(it!=visit.end() && !it->second)
                        {
                            level.insert(tmp);
                            graph[cur].push_back(tmp);
                        }
                    }
                }
            }
            for(auto i: level) visit[i]=1, q.push(i);//set level as visit, ans push to queue, each string for once
        }
        cur.clear(); ans.clear();
        dfs(start);
        return ans;
    }
    void dfs(string i)
    {
        if(i==end_)
        {
            cur.push_back(end_);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        for(auto s: graph[i])
        {
            cur.push_back(i);
            dfs(s);
            cur.pop_back();
        }
    }
};