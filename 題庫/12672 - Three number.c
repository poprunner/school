#include <stdio.h>
int main()
{
	int a, b, c, sum;
	scanf("%d%d%d",&a,&b,&c);
	sum = (a + b + c) / 2;
	printf("%d %d %d\n",sum-b,sum-c,sum-a);
	return 0;
}
