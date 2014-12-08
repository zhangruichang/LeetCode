#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
class Solution {
public:
    double pow(double x, int n) {
	if(x==0) return 0;
	if(x==1) return 1;
	
	if(n>=0)
        return powx(x,ll(n));
	else
		return 1/powx(x,-ll(n) ); 
    }
	double powx(double x, ll n)
	{
		if(n==0ll) return 1;
		if (n==1ll)
			return x;
		//double pro=1;
		//for(int i=0;i<n/2;i++)
		//	pro*=x;
		double result=powx(x,n/2ll);
		if(n&1)
			return result*result*x;
		else 
			return result*result;
		//return powx(x,n/2)*powx(x,n/2);
	}
    double pow(double x, int n) {
        if(n==0) return 1;
        else if(n<0) return 1/pow(x,-(n+1))/x;
        else
        {
            if(n&1) return x*pow(x,n-1);
            else
            {
                double tmp=pow(x,n>>1);
                return tmp*tmp;
            }
        }
    }
} F;

int main()
{
	cout<<F.pow(2,100)<<endl;
	cout<<pow(2,100)<<endl;
	return 0;
}