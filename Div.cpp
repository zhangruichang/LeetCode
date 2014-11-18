#include <iostream>
#include <ctime>
using namespace std;
typedef long long LL;
int divide_minus(int a, int b)
{
	bool same=1;
	if(a<0 && b<0)
		a=-a,b=-b;
	else if(a<0 && b>0)
		a=-a,same=0;
	else if(a>=0 && b<0)
		b=-b,same=0;
	int cnt=0;
	while(a>b)
		a-=b,cnt++;
	return same==1 ? cnt : -cnt;
}

int divide_shift(int a, int b)
{
	LL al=LL(a),bl=LL(b);
	bool same=1;
	if(al<0 && bl<0)
		al=-al,bl=-bl,same=1;
	else if(al<0 && bl>0)
		al=-al,same=0;
	else if(al>=0 && bl<0)
		bl=-bl,same=0;
	else
		same=1;
	LL tmp;
	LL tnt=0,cnt;
	
	while(al>0)
	{	
		tmp=bl;cnt=1;
		if(tmp>al) break;
		while(tmp<=al)
			tmp<<=1,cnt<<=1;
		tmp>>=1;
		tnt+=(cnt>>1);
		al-=tmp;
	}
	return same==true ? tnt : -tnt;
}

int main()
{
	time_t start=clock();
	cout<<divide_shift(-2147483648, 2)<<"\n";
	time_t end=clock();
	cout<<"\n"<<end-start<<"\n";
	return 0;
}