/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
}
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
int a[maxn];
struct Node
{
    bool isWord;
    int Wordsi;
    Node* Child[26];
    Node()
    {
        isWord=0;
        Wordsi=-1;
        //for(int i=0;i<26;i++) Child[i]=NULL;
		fill_n(Child, 26, nullptr);
    }
};
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
class Solution {
public:

    bool outrange(int i, int j)
    {
        return i>=m || i<0 || j>=n || j<0;
    }


    bool v[300][300];
    vector<string> board_;
    int m,n;
    vector<string> ans, words_;
    Node *root;
    vector<string> findWords(vector<string>& board, vector<string>& words) {
        ans.clear();
        board_=board;
        words_=words;
        root=new Node();
        m=board_.size(), n=board_[0].size();
        BuildTrie();
        //dfs(root);
        Found();
        return ans;
    }
    void dfs(Node* root)
    {
        if(!root) return ;
        for(int i=0;i<26;i++)
        {
            if(!root->Child[i]) continue;
            cout<<char(i+'a')<<" ";
            dfs(root->Child[i]);
        }
    }
    void BuildTrie()
    {
        for(unsigned int i=0;i<words_.size();i++)
        {
            string e=words_[i];
            Node* p=root;
            for(unsigned int j=0;j<e.size();j++)
            {
				char se=e[j];
                int index=se-'a';
                if(!p->Child[index]) p->Child[index]=new Node();
                p=p->Child[index];
            }
            p->isWord=1;
            p->Wordsi=i;
        }
    }

    void Found()
    {

        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        {
            memset(v, 0, sizeof v);
            dfs(i, j,root);
        }
    }

    void dfs(int i, int j, Node*p)
    {
        if(outrange(i, j)) return ;
        if(v[i][j]) return ;

        if(!p->Child[board_[i][j]-'a']) return ;
        //if(word[cur]!=) return 0;
        if(p->Child[board_[i][j]-'a']->isWord)
        {
            p->Child[board_[i][j]-'a']->isWord=0;
            ans.push_back(words_[p->Child[board_[i][j]-'a']->Wordsi]);
            return ;
        }
        v[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k], ny=j+dy[k];
            if(outrange(nx, ny)) continue;;
            dfs(nx, ny, p->Child[board_[i][j]-'a']);
        }
        v[i][j]=0;
        //return 0;
    }

} S;

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    /*
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin
        printf("Case #%d:\n", ti);
        cout
    }*/
    vector<string> board={"ab","cd"};
    vector<string> words={"ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"};
    auto ans=S.findWords(board, words);
    for(auto e : ans) cout<<e<<endl;
	return 0;
}
