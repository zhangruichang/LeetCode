#include <iostream>
using namespace std;
class Solution {
public:
	int maxProduct(int a[], int n)
	{
		if(n<=0) return 0;
		int localmin=a[0],localmax=a[0],maxn=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>=0)
			{
				localmax=max(localmax*a[i],a[i]);
				localmin=min(localmin*a[i],a[i]);
				maxn=max(maxn,localmax);
			}
			else
			{
				int tmp=localmax;
				localmax=max(localmin*a[i],a[i]);
				localmin=min(tmp*a[i],a[i]);
				maxn=max(maxn,localmax);
			}
		}
		return maxn;
	}
/*
    int maxProduct(int A[], int n) {
        int maxproduct=0,product=1;
        if(n==1) return A[0];
        for(int i=0;i<n;i++)
        {
            product=A[i];
            maxproduct=max(maxproduct,product);
            for(int j=i+1;j<n;j++)
            {
                product*=A[j];
                maxproduct=max(maxproduct,product);
            }
            //maxproduct=max(maxproduct,product);
        }
        
        return maxproduct;
    }
    int maxProduct(int A[], int n) {
        int product=1,negcnt=0;
        bool haszero=0;
        for(int i=0;i<n;i++)
        {
            product*=A[i];
            if(A[i]<0) negcnt++;
            if(A[i]==0) haszeor=1;
        }
        if(negcnt&1==0 && !haszero) return product;
        
    }
    int maxProduct(int A[], int n)
    {
        int product=1,maxproduct;
        dp[0]=A[0],maxproduct=dp[0];
        int start=0;
        for(int i=1;i<n;i++)
        {
            if(A[i]>0) dp[i]=dp[i-1]*A[i],maxproduct=max(maxproduct,dp[i]);
            else
            {
                int j=start;
                while(A[j]>0 && j<i)
                    j++;
                if(j==i)
                {
                    start=i;
                    //dp[]
                }
                else
                {
                    
                }
            }
        }
    }*/
    int maxSubProduct(int s, int e, int A[],int product)
    {
        //if(s>e) return 0;
        int beforeprod=1,afterprod;
        int maxn;
        for(int i=s;i<=e;i++)
        {
            beforeprod*=A[i];
            afterprod=(product/beforeprod)*A[i];
            maxn=max(beforeprod,afterprod);
        }
        return maxn;
    }
    
    int maxProduct_Zhan(int A[], int n)
    {
        if(n==0 || A==NULL) return 0;
        if(n==1) return A[0];
        int s=0;//e=-1;
        //bool first=1;
        int product=1,maxproduct=0;
        
        
        
        for(int i=0;i<n;i++)
        {
            if(A[i]!=0)
                product*=A[i];
            else
            {
                if(s<=(i-1))
                {    
                    if(product<0)
                        maxproduct=max(maxproduct,maxSubProduct(s,i-1,A,product));
                    else
                        maxproduct=max(maxproduct,product);
                }
                s=i+1;
                product=1;
                cout<<maxproduct<<endl;
            }
        }
        if(A[n-1]!=0)
            maxSubProduct(s,n-1,A,product);
        return maxproduct;
    }
    
    
} F;

int main()
{
    int A[]={7,-2,-4};
    cout<<F.maxProduct(A,sizeof(A)/sizeof(int))<<endl;
    return 0;
}