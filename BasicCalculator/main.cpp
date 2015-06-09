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
int a[maxn], n, t, m;
int stoi(string s)
{
    int num=0;
    for(auto e: s) num=num*10+e-'0';
    return num;
}
class Solution {
public:
    string Pri[5]={"=<<<?",
    ">>><>",
    ">>><>",
    "?<<<=",
    ">>>?>"};
    int index(char op)
    {
        if(op=='#') return 0;
        else if(op=='+') return 1;
        else if(op=='-') return 2;
        else if(op=='(') return 3;
        else return 4;
    }
    int calculate(string s)
    {
        s.push_back('#');
        int n=s.size();
        stack<int> stnum;
        stack<char> stop;
        stop.push('#');
        int i=0;
        while(i<n && (s[i]!='#' || stop.top()!='#'))
        {
            while(i<n && s[i]==' ') i++;
            if(i==n) break;
            if(isdigit(s[i]))
            {
                int si=i++;
                while(i<n && isdigit(s[i])) i++;
                stnum.push(stoi(s.substr(si, i-si)));
            }
            else
            {
                char etop=stop.top(), ecur=s[i];
                char pri=Pri[index(etop)][index(ecur)];
                if(pri=='<')
                {
                    stop.push(ecur);
                    i++;
                }
                else if(pri=='=')
                {
                    stop.pop();
                    i++;
                }
                else
                {
                    int num2=stnum.top();stnum.pop();
                    int num1=stnum.top();stnum.pop();
                    char e=stop.top(); stop.pop();
                    int ans= ( (e=='+') ? (num1+num2) : (num1-num2));
                    stnum.push(ans);
                }
            }
        }
        //cout<<stnum.size()<<endl;
        return stnum.top();
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
    string s="(1+(4+5+2)-3)+(6+8)";
    cout<<S.calculate(s);
	return 0;
}
