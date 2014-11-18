#include <cmath>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
		if(x==0) return 1;
		//int bit[32];
		int biti=0,tmp=x;
		while(tmp>0)
			biti++,tmp/=10;	
		
		for(int i=0;i<biti-1;)
		{
			//cout<<i<<" "<<x<<" \n";
			//cout<<x%10<<" "<<x/(int)pow(10,biti-i-1)<<"\n";
			if(x%10 != x/(int)pow(10,biti-i-1)) return 0;
			
			x-=(x%10)*pow(10,biti-i-1);
			x/=10;
			biti-=2;
		}
			
		return 1;
    }
	
	
} F;

int main()
{
	cout<<F.isPalindrome(11)<<"\n";
	return 0;
}