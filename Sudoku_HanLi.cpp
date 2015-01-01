class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector< vector<bool> > row(9,vector<bool>(9,false));
        vector< vector<bool> > col(9,vector<bool>(9,false));
        vector< vector<bool> > block(9,vector<bool>(9,false));
        int index=0;
        int i,j,num;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    num = board[i][j]-'1';
                    row[i][num]=col[j][num]=block[3*(i/3)+j/3][num]=true;
                }
            }
        }
        
        vector< vector<char> > res(9,vector<char>(9,'.'));
        
        bool flag=false;
        solve(flag,index,res,board,row,col,block);
        int m,n;
        for(m=0;m<9;m++)
        {
            for(n=0;n<9;n++)
            {
                board[m][n] = res[m][n];
            }
        }
    }
    void solve(bool &flag,int index,vector< vector<char> > &res,vector< vector<char> > &board,vector< vector<bool> > &row,vector< vector<bool> > &col,vector< vector<bool> > &block)
    {
        int n,m;
        
        int x,y;
        x = index/9,y = index%9;
        int i;
        
        if(x==9&&y==0)
        {
            flag = true;
            for(m=0;m<9;m++)
            {
                for(n=0;n<9;n++)
                {
                    res[m][n] = board[m][n];
                }
            }
            return;
        }
        if(board[x][y]!='.')
        {
            if(flag == true) return;
            solve(flag,index+1,res,board,row,col,block);
            return;
        }
        for(i=0;i<9;i++)
        {
            if(flag==true) break;
            if(row[x][i]||col[y][i]||block[3*(x/3)+y/3][i]) continue;
            board[x][y] = i+'1';
            row[x][i] = col[y][i] = block[3*(x/3)+y/3][i] = true;
            solve(flag,index+1,res,board,row,col,block);
            row[x][i] = col[y][i] = block[3*(x/3)+y/3][i] = false;
            board[x][y] = '.';
        }
    }
    
};