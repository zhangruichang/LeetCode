#include <cstdio>
int main()
{
	const int i=10;
	int* p = (int*)(&i);
	*p=0;
	printf("%d\n",*p);
	printf("%ld",i);
	return 0;
}