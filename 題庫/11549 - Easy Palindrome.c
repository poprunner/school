/*#include <stdio.h>
int main(){
	double h,k;
	int a,b,c;
	scanf("%lf",&h);
	a=(int)1000*h;		//*1000換成整數  變成一六位數 
	b=(a/1000)%10*100+(a/1000)/10%10*10+(a/1000)/100;//整數區三位數交換 
	c=(a%1000)%10*100+(a%1000)/10%10*10+(a%1000)/100;//小數區三位數交換 
	k=(double)(1000*b+c)/1000;//1000*b+c  變成六位數整數  轉換成浮點數型別  /1000回歸為三位數小數 
	printf("%.3f",k+h);	//兩小數相加 
	return 0;
}
*/
/*
#include <stdio.h>
int main(){
	double h;
	scanf("%lf",&h);
	printf("%.3f",h+
					(double)
						(
						1000
						*(((int)(1000*h)/1000)%10*100+((int)(1000*h)/1000)/10%10*10+((int)(1000*h)/1000)/100)
						+(((int)(1000*h)%1000)%10*100+((int)(1000*h)%1000)/10%10*10+((int)(1000*h)%1000)/100)
						)
					/1000
					);
	return 0;
}
*/





#include <stdio.h>
int main()
{
	int a, b, ai, bi;
	double x, y;
	scanf("%d.%d",&a,&b);
	ai = a/100 + (a/10)%10*10 + a%10*100;
	bi = b/100 + (b/10)%10*10 + b%10*100;
	x = (double)(1000*a + b) / 1000;
	y = (double)(1000*ai + bi) / 1000;
	printf("%.3f",x+y);
	return 0;
}
