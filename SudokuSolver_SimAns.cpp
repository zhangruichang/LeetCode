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
public:
    int n;
    int row[9][9],col[9][9],grid[9][9];
    void solveSudoku(vector<vector<char> > &board) {
        //n=board.size();
        memset(row,0,sizeof(row));memset(col,0,sizeof(col));memset(grid,0,sizeof(grid));
        for(int i=0;i<9;i++) for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.') row[i][board[i][j]-'0'-1]=1,grid[(i/3) * 3+ (j/3)] [board[i][j]-'0'-1]=1;
        }
        for(int j=0;j<9;j++) for(int i=0;i<9;i++)
            if(board[i][j]!='.') col[board[i][j]-'0'-1][j]=1;
        dfs(board);
    }
    bool dfs(vector<vector<char> >& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k=1;k<=9;k++)
                    {
                        board[i][j]=k+'0';
                        if(IsValid(board,i,j) && dfs(board))
                            return 1;
                        //row[i][board[i][j]-'1']== 0,col[board[i][j]-'1'][j]== 0,grid [(i/3)*3+j/3] [board[i][j]-'1'] == 0;
                        board[i][j]='.';   
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    bool IsValid(const vector<vector<char> >& board, int x, int y)
    {
        for(int i=0;i<9;i++)
            if(i!=x && board[x][y] == board[i][y]) return 0;//same col
        for(int j=0;j<9;j++)
            if(j!=y && board[x][y] == board[x][j]) return 0;
        for(int i=(x/3)*3,k=0;k<3;k++)
            for(int j=(y/3)*3,l=0;l<3;l++)
                if((i+k)!=x && (j+l)!=y && board[i+k][j+l]==board[x][y]) return 0;
        //if(row[i][board[i][j]-'1']== 1 || col[board[i][j]-'1'][j]== 1 || grid [(i/3)*3+j/3] [board[i][j]-'1'] == 1 ) return 0;
        //row[i][board[i][j]-'1']== 1,col[board[i][j]-'1'][j]== 1,grid [(i/3)*3+j/3] [board[i][j]-'1'] == 1;
        return 1;
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