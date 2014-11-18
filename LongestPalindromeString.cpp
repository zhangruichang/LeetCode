#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
string str,newstr;
int j,k,mx,maxp,id;
int P[1000000];
void LPS()//2n+1
{
    P[0]=1;P[1]=2;//len at least 1
    id=1, mx=id+P[id], maxp=1;
    int len=newstr.size();
    for(int i=2;i<=len-1;i++)
    {
        j=2*id-i;
        if(mx-i>=P[j])
            P[i]=P[j];
        else
        {
            P[i]=mx-i;
            while(i+P[i]<=len-1 && i-P[i]>=0 && str[i+P[i]]==str[i-P[i]])
                P[i]++;
        }
        
        /*
        P[i]=min(mx-i,P[j]);
        k=mx-i;
        while(i+k<len && i-k>=0 && newstr[i+k]==newstr[i-k])
            k++;
        P[i]=k+1;
        */
        
        if(mx<i+P[i])
        {
            id=i;
            mx=id+P[id];
        } 
        if(maxp<P[i]-1)
            maxp=P[i]-1;
    }
}

void Extend()
{
    string newstr="#";
    for(int i=0;i<str.size();i++)
    {
        newstr+=(str[i]+"#");
    }
    cout<<newstr<<endl;
}

int main()
{
    freopen("LPS_in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    while(cin>>str)
    {
        Extend();
        LPS();
        printf("%d\n",maxp);
    }
    return 0;
}