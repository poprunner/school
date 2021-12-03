/*#include<stdio.h>
int main(){
	int a,b,c,d;
	double e;
	scanf("%d.%d %d.%d",&a,&b,&c,&d);
	e=(a+0.01*b)*(c+0.01*d);
	printf("%.4f\n",e);
	return 0;
}*/




#include <stdio.h>
int main()
{
	double a, b;
	scanf("%lf%lf",&a,&b);
	printf("%.4f\n",a*b);		//要用 %.4f 小數點後到第4位 並沒有說前面要補0 
	return 0;
}
