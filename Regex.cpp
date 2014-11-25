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
	bool  isMatch(const  char  *s,  const  char  *p)  {
		if  (*p  ==  '\0')  return  *s  ==  '\0';
		//  next  char  is  not  '*',  then  must  match  current  character
		if  (*(p  +  1)  !=  '*')  
		{
			if  (*p  ==  *s  ||  (*p  ==  '.'  &&  *s  !=  '\0'))
				return  isMatch(s  +  1,  p  +  1);
			else
				return  false;
		}
		else  
		{  //  next  char  is  '*'
			while  (*p  ==  *s  ||  (*p  ==  '.'  &&  *s  !=  '\0'))  
			{
				if  (isMatch(s,  p  +  2))
					return  true;
				s++;
			}
			return  isMatch(s,  p  +  2);
		}
    }
};

int main()
{
    
    return 0;
}