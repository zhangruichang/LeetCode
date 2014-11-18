#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int m=a.size(),n=b.size();
		int maxlen=max(m,n);
		
		for(int i=0;i<maxlen;i++)
		{
			if(i>=m) a+='0';
			else if(i>=n) b+='0';
		}
		string c;int carry=0;
		for(int i=0;i<maxlen;i++)
		{
			c+=((a[i]-'0'+b[i]-'0'+carry)%2+'0');
			carry=(a[i]-'0'+b[i]-'0'+carry)/2;
		}
		if(carry) c+='1';
		reverse(c.begin(),c.end());
		return c;
	}
} F;
int main()
{
	cout<<F.addBinary("111111111","1")<<endl;
}