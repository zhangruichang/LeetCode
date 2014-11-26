#include <iostream>

using namespace std;
typedef unsigned long long ULL;

class Solution {
public:
    int sqrt(int x) {
        if(x==1 || x==0) return x;
        double low=0,high=x;
        while((high-low) >= 1e-5)
        {
            double mid=(low+high)/2;
            if(mid*mid>x)
                high=mid;
            else if(mid*mid<x)
                low=mid;
            else
                return mid;
        }
        return (int)(high-(1e-8));
    }

    int sqrt_1(int x)
    {
        if(x==0 || x==1) return x;
        ULL low=1,high=x-1;
        while(low<high)
        {
            if(low+1==high)
            {
                if(high*high<=(ULL)x) return high;
                else if(high*high>(ULL)x)
                {
                    if(low*low<=(ULL)x) return low;
                }
            }
            ULL mid=(low+high)/2;
            if(mid*mid<x)
                low=mid;
            else if(mid*mid>x)
                high=mid-1;
            else
                return mid;
        }
        return low;
    }
} F;

int main()
{
    int x;
    while(cin>>x)
        cout<<F.sqrt_1(x)<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
