#include <iostream>

using namespace std;


void PrintPrime(int n)//Print 1..n Prime
{
    bool isPrime[n+1];
    for(int i=0;i<=n;i++) isPrime[i]=1;
    isPrime[1]=0,isPrime[2]=1;isPrime[3]=1;//isPrime[4]=0;
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=n;j+=i)
                isPrime[j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(isPrime[i])
            cout<<i<<" ";
    }
    cout<<endl;
}

void NextPrime(int n)
{
    int next=n+1,i;
    if(next%2==0) next++;
    for(int j=next;;j+=2)
    {
        //if(j%2==0) continue;
        for(i=3;i*i<=j;i+=2)
        {
            if(j%i==0)
                break;
        }
        if(i*i>j)
        {
            cout<<j;
            break;
        }
    }
}

int main()
{
    PrintPrime(1000);
    NextPrime(566);
    return 0;
}
