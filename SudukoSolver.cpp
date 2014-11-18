#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

class Solution {
private:
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};//up, down, left, right
    bool row[9][9],col[9][9],grid[9][9],visit[9][9];
    //int _dotcnt;
    vector<vector<char> > ans;
    void dfs(int i, int j,vector<vector<char> >& board,int dotcnt)
    {
        if(dotcnt==0) {ans=board;return;}
        
        
        //bool ok=0;
        for(int k=1;k<=9;k++)
        {
            if(!grid[(i/3) *3 + (j/3)][k-1] && !row[i][k-1] && !col[k-1][j])
            {    
                
                //{
                    board[i][j]=k+'0';//if(dotcnt-1==0) {ans=board;return ;}
                    for(int dk=0;dk<4;dk++)
                    {
                        int nx=i+dx[dk],ny=j+dy[dk];
                        if(nx<=8 && nx>=0 && ny<=8 && ny>=0 && board[nx][ny]=='.')
                            dfs(nx,ny,board,dotcnt-1);
                    }
                    board[i][j]='.';
                //}
            }
        }
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        int dotcnt=0;memset(row,0,sizeof(row));memset(col,0,sizeof(col));memset(grid,0,sizeof(grid));
        for(int i=0;i<9;i++) for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.') row[i][board[i][j]-'0'-1]=1,grid[(i/3) * 3+ (j/3)] [board[i][j]-'0'-1]=1;
            if(board[i][j]=='.') dotcnt++;
        }
        for(int j=0;j<9;j++) for(int i=0;i<9;i++)
            if(board[i][j]!='.') col[board[i][j]-'0'-1][j]=1;
        
        ans.clear();
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') dfs(i,j,board,0);
                board=ans;
                //if(ans.size()!=0) {board=ans;return;}
            }
        }
    }
} F;

int main()
{
    vector<vector<char> > board({{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}});
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
            cout<<board[i][j];
        cout<<endl;
    }
    F.solveSudoku(board);
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
            cout<<board[i][j];
        cout<<endl;
    }
	return 0;
}