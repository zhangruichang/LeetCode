#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
class Solution {
public:
    bool isNumber(const char *s) {
        while(*s && *s==' ') s++;
        if(!(*s)) return 0;
        if(*s=='+' || *s=='-') s++;
        
        if((*s>'9' || *s<'0') && *s!='.') return 0;
        
        while(*s && *s<='9' && *s>='0') s++;
        if(!(*s)) return 1;
        
        
        if(*s=='.' || *s=='e' || *s=='E') s++;
        else
          return 0;
          
        if(*s=='.'||*s=='e' || *s=='E')
        {
          while(*s && *s<='9' && *s>='0') s++;
          if(!(*s)) return 1;
        }

        if(!(*s))
          return 1;
        else
          return 0;
    }
} F;

int main()
{
  char s[100];
  while(gets(s))
  {
    printf("%s\n",s);
    cout<<F.isNumber(s)<<"\n\n";
  }
  return 0;
}