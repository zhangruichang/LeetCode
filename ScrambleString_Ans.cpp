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
#include <ctime>
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
bool  isScramble(string  s1,  string  s2)  {
const  int  N  =  s1.size();
if  (N  !=  s2.size())  return  false;
//  f[n][i][j]，表示长度为 n，起点为 s1[i]  和
//  起点为 s2[j]  两个字符串是否互为 scramble
bool  f[N  +  1][N][N];
fill_n(&f[0][0][0],  (N  +  1)  *  N  *  N,  false);
for  (int  i  =  0;  i  <  N;  i++)
for  (int  j  =  0;  j  <  N;  j++)
f[1][i][j]  =  s1[i]  ==  s2[j];
for  (int  n  =  1;  n  <=  N;  ++n)  {
for  (int  i  =  0;  i  +  n  <=  N;  ++i)  {
for  (int  j  =  0;  j  +  n  <=  N;  ++j)  {
for  (int  k  =  1;  k  <  n;  ++k)  {
if  ((f[k][i][j]  &&  f[n  -  k][i  +  k][j  +  k])  ||
(f[k][i][j  +  n  -  k]  &&  f[n  -  k][i  +  k][j]))  {
f[n][i][j]  =  true;
break;
}
}
}
}
}
return  f[N][0][0];
}
} F;

int main()
{
    cout<<F.isScramble("rgtae","great")<<endl;
    return 0;
}