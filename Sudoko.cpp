#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#define px p.first
#define py p.second
using namespace std;
class Solution {
public:
    bool found[9];
    bool isValidSudoku(vector<vector<char>> &board) {
        
        for(int i=0;i<=6;i+=3)
        {
            for(int j=0;j<=6;j+=3)
            {
                //si=i,sj=j;
                memset(found,0,sizeof(found));
                for(int si=0;si<=2;si++)
                {
                    for(int sj=0;sj<=2;sj++)
                    {
                        if(board[i+si][j+sj]!='.')
                        {
                            if(found[board[i+si][j+sj]-'0'-1]==false)
                            {
                                found[board[i+si][j+sj]-'0'-1]=true;
                            }
                            else
                                return false;
                        }
                    }
                }
            }
        }
        for(int i=0;i<=8;i++)
        {
            memset(found,0,sizeof(found));
            for(int j=0;j<=8;j++)
            {
                if(board[i][j]!='.')
                {
                    if(found[board[i][j]-'0'-1]==false)
                    {
                        found[board[i][j]-'0'-1]=true;
                    }
                    else
                        return false;
                }
            }
        }
        for(int j=0;j<=8;j++)
        {
            memset(found,0,sizeof(found));
            for(int i=0;i<=8;i++)
            {
                if(board[i][j]!='.')
                {
                    if(found[board[i][j]-'0'-1]==false)
                    {
                        found[board[i][j]-'0'-1]=true;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
    
    /*
    bool isValidSudoku2(vector<vector<char> > &board) {//board 9 * 9
        queue <pair<int, int>> q;
        q.push({0,0});
        for(int i=0;i<9;i++)
            memset(visit[i],0,sizeof(visit[i]));
        while(!q.empty())
        {
            p=q.front();
            visitp[px][py]=1;
            q.pop();
            if(board[px][py]!='.')
            {
                if(px-1>=0 && !visit[px-1][py])
                    q.push({px-1,py});
                if(px+1<=8 && !visit[px+1][py])
                    q.push({px+1,py});
                if(py-1>=0 && !visit[px][py-1])
                    q.push({px,py-1});
                if(py+1<=8 && !visit[px][py+1])
                    q.push({px,py+1});
            }
            else
            {
                for(int fillnum=1;filnum<=9;fillnum++)
                {
                    if(Valid(make_pair<px, py>, fillnum))
                    {
                        board[px][py]=fillnum;
                        
                        if(px-1>=0 && !visit[px-1][py])
                            q.push({px-1,py});
                        if(px+1<=8 && !visit[px+1][py])
                            q.push({px+1,py});
                        if(py-1>=0 && !visit[px][py-1])
                            q.push({px,py-1});
                        if(py+1<=8 && !visit[px][py+1])
                            q.push({px,py+1});
                    }
                }
            }
        }
    }*/
};

int main()
{
    vector<vector<char> > board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},{'.','.','.','3','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    cout<<board.size()<<endl;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            printf("%c",board[i][j]);        
        }
        puts("");
    }
    Solution S;
    printf("%d\n",S.isValidSudoku(board));
    
    
    /*
    vector<char> row2{'6','.','.','1','9','5','.','.','.'};
    vector<char> row3{'.','9','8','.','.','.','.','6','.'};
    vector<char> row4{'8','.','.','.','6','.','.','.','3'};
    vector<char> row5{'4','.','.','8','.','3','.','.','1'};
    vector<char> row6{'7','.','.','.','2','.','.','.','6'};
    vector<char> row7{'.','6','.','.','.','.','2','8','.'};
    vector<char> row8{'.','.','.','4','1','9','.','.','5'};
    vector<char> row9{'.','.','.','.','8','.','.','7','9'};*/
    return 0;
}