#include <cstdio>
#include <iostream>
#include <cctype>
using namespace std;


int main()
{
    //freopen("in.txt","r",stdin);
    char line[1000];
    gets(line);
    //bool start=0;int cnt=0;
    int maxcnt=0,repcnt=0,spos=0,maxspos=0;
    bool start=0;
    for(int i=0;line[i];i++)
    {
        if(!i || line[i]==line[i-1])
        {
            if(start==0)
                spos=i-1,start=1;
            repcnt++;
        }
        else
        {
            if(maxcnt<repcnt)
                maxcnt=repcnt,maxspos=spos;
            //maxcnt=max(maxcnt,repcnt);
            repcnt=1,start=0;;
        }
    }
    maxcnt=max(maxcnt,repcnt),repcnt=1;
    printf("%d %d\n",maxcnt, spos);
    return 0;
}