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

class  Solution  {
public:
	bool  solveSudoku(vector<vector<char>  >  &board)  {
		for  (int  i  =  0;  i  <  9;  ++i)
        {
			for  (int  j  =  0;  j  <  9;  ++j)  
            {
				if  (board[i][j]  ==  '.')  
                {
					for  (int  k  =  0;  k  <  9;  ++k)  
                    {
						board[i][j]  =  '1'  +  k;
						if  (isValid(board,  i,  j)  &&  solveSudoku(board))
							return  1;
						board[i][j]  =  '.';
					}
					return  0;
				}
			}
        }
        return  1;
	}
private:
	//  检查 (x,  y)  是否合法
	bool  isValid(const  vector<vector<char>  >  &board,  int  x,  int  y)  {
		int  i,  j;
		for  (i  =  0;  i  <  9;  i++)  //  检查 y  列
			if  (i  !=  x  &&  board[i][y]  ==  board[x][y])
				return  0;
		for  (j  =  0;  j  <  9;  j++)  //  检查 x  行
			if  (j  !=  y  &&  board[x][j]  ==  board[x][y])
				return  0;
		for  (i  =  3  *  (x  /  3);  i  <  3  *  (x  /  3  +  1);  i++)
			for  (j  =  3  *  (y  /  3);  j  <  3  *  (y  /  3  +  1);  j++)
				if  ((i  !=  x  ||  j  !=  y)  &&  board[i][j]  ==  board[x][y])
					return  0;
		return  1;
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