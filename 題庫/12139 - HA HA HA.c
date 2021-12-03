/*#include <stdio.h>
#include<stdlib.h>
int gcd(int a,int b){
	if(a%b==0)
		return b;
	gcd(b,a%b);
}
int main(void){
	int n,i,j,max=0;
	int *k;
	scanf("%d",&n);
	k=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&k[i]);
	}
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(gcd(k[i],k[j])>=max)
				max=gcd(k[i],k[j]);
	printf("%d\n",max);
	return 0;
}*/

/* 
#include <stdio.h>
int a[1000];
int gcd(int a,int b)
{
	if(b == 0) return a;
	gcd(b,a%b);
}
int main()
{
	int n, i, j, ans, max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			ans = gcd(a[i],a[j]);
			if(ans > max) max = ans;
		}
	printf("%d\n",max);
	return 0;
} */





#include <stdio.h>
int a[1000];
int gcd(int i,int j)
{
	if(j == 0) return i;
	return gcd(j,i%j);
}
int main()
{
	int n, i, j, rem, max = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]); 
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			rem = gcd(a[i],a[j]);		//記得傳進 gcd 的值是 a[i],a[j] 不要打成 i,j 
			if(rem > max) max = rem;
		}
	printf("%d\n",max);
	return 0;
}
