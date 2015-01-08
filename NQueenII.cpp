class Solution {
public:
    vector<bool> col, main, second;
    vector<string> board;
    vector<vector<string> > ans;
    int n_;
    vector<vector<string> > solveNQueens(int n) {
        string row(n,'.');
        n_=n;
        col.assign(n,0);main.assign(2*n-1,0);second.assign(2*n-1,0);//此处用assign最合适，因为只需要前面几项, 尽量不在外面初始化
        board.clear();ans.clear();
        for(int i=0;i<n;i++) board.push_back(row);
        dfs(0);
        return ans;
    }
    bool canPut(int rowi ,int colj)
    {
        if(col[colj]) return 0;
        if(main[n_-1-(rowi-colj)]) return 0;//此处写的太快，没完全想清楚，求速度写错了，写成rowi-colj-(n_-1), 只对觉得rowi=n-1, colj=0, 是0，却没考虑后面的情况会变负数，减号两边换一下
        if(second[rowi+colj]) return 0;
        return 1;
    }
    void dfs(int i)
    {
        if(i>=n_)
        {
            ans.push_back(board);
            return ;
        }
        for(int j=0;j<n_;j++)
        {
            if(canPut(i, j))
            {
                board[i][j]='Q';
                col[j]=1;main[n_-1-(i-j)]=1;second[i+j]=1;
                dfs(i+1);
                col[j]=0;main[n_-1-(i-j)]=0;second[i+j]=0;
                board[i][j]='.';
            }
        }
    }
};