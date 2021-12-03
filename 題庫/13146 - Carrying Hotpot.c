#include <stdio.h>
int main()
{
	double a, b;
	int z;
	scanf("%lf%lf%d",&a,&b,&z);
	printf("%.*f",z,a*b);
	return 0;
}
