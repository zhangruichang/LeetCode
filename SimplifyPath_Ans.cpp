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
#include <sstream>
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
    string  simplifyPath(string  const&  path)  {
        vector<string>  dirs;  //  当做栈  
        for  (auto  i  =  path.begin();  i  !=  path.end();)  {
        ++i;
        auto  j  =  find(i,  path.end(),  '/');
        auto  dir  =  string(i,  j);
        if  (!dir.empty()  &&  dir  !=  ".")  {//  当有连续 '///'  时，dir  为空
        if  (dir  ==  "..")  {
        if  (!dirs.empty())
dirs.pop_back();
}  else
dirs.push_back(dir);
}
i  =  j;
    }
    stringstream  out;
    if  (dirs.empty())  {
    out  <<  "/";                                                                                                         
    }
    else  {
        for  (auto  dir  :  dirs)
            out  <<  '/'  <<  dir;
    }
    return  out.str();
}
} F;

int main()
{
   cout<<F.simplifyPath("/...")<<endl;
   return 0;
}