//swap, remove duplicate
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> num_;
    int n;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        n=num.size();num_=num;
        ans.clear();
        dfs(0);
        return ans;
    }
    bool Duplicate(int i, int j)
    {
        for(int k=i;k<j;k++) if(num_[k]==num_[j]) return 1;
        return 0;
    }
    void dfs(int i)
    {
        if(i>=n)
        {
            ans.push_back(num_);
            return ;
        }
        for(int j=i;j<n;j++)
        {
            if(!Duplicate(i, j))
            {
                swap(num_[j], num_[i]);
                dfs(i+1);
                swap(num_[j], num_[i]);
            }
        }
    }
};

//dfs, OLE, output limit exceed, use cur, and visit, use prev to remove duplicate
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> cur, num_;
    int n;
    bool u[10000];
    vector<vector<int> > permuteUnique(vector<int> &num) {
        n=num.size();num_=num;
        memset(u, 0, sizeof(u));
        ans.clear(), cur.clear();
        dfs(0);
        return ans;
    }
    void dfs(int i)
    {
        if(i>=n)
        {
            ans.push_back(cur);
            return ;
        }
        int prev=-1;
        for(int j=0;j<n;j++)
        {
            if(!u[j] && num_[j] != prev)
            {
                u[j]=1;
                cur.push_back(num_[j]);
                dfs(i+1);
                cur.pop_back();
                u[j]=0;
                prev=num_[j];
            }
        }
    }
};