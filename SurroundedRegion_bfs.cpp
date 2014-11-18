#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

class Solution {

public:

	bool visit[800][800];
	//vector<vector<char> > _b;
  int m,n;
	int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};//up, down, left, right
    
  void bfs(int i, int j, vector<vector<char> > & _b )//m rows, n cols
  {
    queue<pair<int, int> > q;
    q.push({i,j});
    while(!q.empty())
    {
      auto p=q.front();
      int x=p.first, y=p.second;
      visit[x][y]=1;
      q.pop();
      
      for(int k=0;k<4;k++)
      {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx<=m-1 && nx >=0 && ny <=n-1 && ny >= 0 && !visit[nx][ny] && _b[nx][ny] == 'O') {
          visit[nx][ny] = true;
          q.push({nx,ny});
        }
      }
    }
  }
    
  void solve(vector<vector<char> > &_b) {
		m=_b.size();//row
		if(m<=0) return;
		n=_b[0].size();//col
		if(n<=0) return;
		//_b=board;
		memset(visit,0,sizeof(visit));
		for(int j=0;j<n;j++)
		{
			if(!visit[0][j] && _b[0][j]=='O')
				bfs(0,j,_b);
			if(!visit[m-1][j] && _b[m-1][j]=='O')
				bfs(m-1,j,_b);
		}
		for(int i=1;i<m-1;i++)
		{
			if(!visit[i][0] && _b[i][0]=='O')
				bfs(i,0,_b);
			if(!visit[i][n-1] && _b[i][n-1]=='O')
				bfs(i,n-1,_b);
		}

    for(int i=1;i<m-1;i++)
    {
      for(int j=1;j<n-1;j++)
      {
        if(_b[i][j]=='O' && !visit[nx][ny])_b[i][j]='X';
      }
    }
  }

} F;

int main()
{
	
  
  vector<string> test({"XOOOOOOOOOOOOOOOOOOO","OXOOOOXOOOOOOOOOOOXX","OOOOOOOOXOOOOOOOOOOX","OOXOOOOOOOOOOOOOOOXO","OOOOOXOOOOXOOOOOXOOX","XOOOXOOOOOXOXOXOXOXO","OOOOXOOXOOOOOXOOXOOO","XOOOXXXOXOOOOXXOXOOO","OOOOOXXXXOOOOXOOXOOO","XOOOOXOOOOOOXXOOXOOX","OOOOOOOOOOXOOXOOOXOX","OOOOXOXOOXXOOOOOXOOO","XXOOOOOXOOOOOOOOOOOO","OXOXOOOXOXOOOXOXOXOO","OOXOOOOOOOXOOOOOXOXO","XXOOOOOOOOXOXXOOOXOO","OOXOOOOOOOXOOXOXOXOO","OOOXOOOOOXXXOOXOOOXO","OOOOOOOOOOOOOOOOOOOO","XOOOOXOOOXXOOXOXOXOO"});
  vector<vector<char> > board1;
  for(int i=0;i<test.size();i++)
  {
    vector<char> line;
    for(int j=0;j<test[i].size();j++)
      line.push_back(test[i][j]);
    board1.push_back(line);
  }
  
  vector<vector<char> > board({{'X','X','O','X'},{'X','O','X','X'},{'X','X','O','X'},{'X','O','X','X'}});
  
  //for(int i=0;i<=1;i++)cout<<test[i]<<'\n';
  
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[0].size();j++)
		{
			cout<<board[i][j]<<' ';
		}
		cout<<"\n";
	}
	cout<<'\n';
	F.solve(board);
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[0].size();j++)
		{
			cout<<board[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}