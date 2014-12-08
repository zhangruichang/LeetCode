#include<stdio.h>  
#include <math.h>
/*
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
#include <sstream>
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

class Solution {
public:
    string add(string num1, string num2)//reversed
    {
        int n1=num1.size(),n2=num2.size();
        int max_len=max(n1,n2);
        if(n1<n2) for(int i=n1;i<max_len;i++) num1+='0';
        else for(int i=n2;i<max_len;i++) num2+='0';
        
        string ans;int carry=0;
        for(int i=0;i<max_len;i++)
        {
            int bit_ans=(num1[i]+num2[i]-2*'0'+carry)%10;
            carry=(num1[i]+num2[i]-2*'0'+carry)/10;
            ans+=(bit_ans+'0');
        }
        if(carry) ans+='1';
        return ans;
    }
    string sin_multiply(string num1, char int1)//reversed
    {
        //reverse(num1.begin(),num1.end());
        int n=num1.size();int tens=1;
        string ans="0";
        for(int i=0;i<=n-1;i++)
        {
            int bit_ans=(num1[i]-'0')*(int1-'0')*tens;//tens=1
            stringstream ss;ss<<bit_ans;
            ans=add(ans,ss.str());
            tens*=10;
        }
        return ans;
    }
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        if(num1.size()<num2.size()) swap(num1, num2);
        //num1 is longer than num2
        string ans="0";
        for(int i=0;i<num2.size();i++)
        {
            string curans=sin_multiply(num1,num2[i]);
            string tmp;
            for(int j=0;j<i;j++) tmp+='0';
            curans=tmp+curans;
            ans=add(ans,curans);
        }
        return ans;
    }
} F;
*/
int main()
{
    int a;char c;bool d;
    int x =3;
    double y=sqrt(x);
    char suf[200] ;
    scanf("%s" , suf) ;
    printf("%s" , suf) ;
    //scanf("%d%c",&a,&c);printf("%d %c", a, c);
    //cout<<F.multiply("834","1")<<endl;
    return 0;
}