/*#include <stdio.h>
int main(void){
	int b[10]={0};
	int n,cnt=0,i,carry=0,can=0;
	scanf("%d",&n);
	while(n!=0){
		b[cnt]=n%2;
		n/=2;
		cnt++;//算其為幾位數(二進位) 
	}
	b[0]=b[0]+1;
	for(i=0;i<cnt;i++){
		if(b[i]==2){
			b[i+1]+=1;
			b[i]=0;
			carry++;//進位carry++ 
		}
	}
	for(i=9;i>=0;i--){
		if(b[i]==1||can){//發現首位數時can++開放列印 
			printf("%d",b[i]);
			can++;
		} 
	}
	printf(" %d",carry);
	cnt=0;//歸零 
	carry=0;
	can=0;
	return 0;
}*/


/*
#include <stdio.h>
int a[10];
int main()
{
	int n, i, cnt = 0, nori, t;
	scanf("%d",&n);
	nori = n+1;
	for(i=0;i<10;i++)
	{
		nori/=2;
		if(nori == 0)
		{
			t = i;
			break;
		}
	}
	for(i=0;i<10;i++)
	{
		a[i] = n%2;
		n/=2;
	}
	a[0]++;
	for(i=0;i<10;i++)
	{
		if(a[i] == 2)
		{
			a[i] = 0;
			a[i+1]++;
			cnt++;
		}
	}
	for(i=t;i>=0;i--){
		printf("%d",a[i]);
	}
	printf(" %d",cnt);
	return 0;
}
*/

#include <stdio.h>
int main()
{
	int bi[10] = {0};
	int n, i, cnt = 0, can = 0;
	scanf("%d",&n);
	for(i=0;i<10;i++)			//轉成2進位 
	{
		bi[i] = n%2;
		n/=2;
	}
	bi[0]++;					//+1 
	for(i=0;i<10;i++)			//2進位+1 如果有進位cnt++ 
	{
		if(bi[i] > 1)
		{
			bi[i] = 0;
			bi[i+1]++;
			cnt++;
		}
	}
	for(i=9;i>=0;i--)			//從高位數印到低位數 
	{
		if(bi[i] > 0) can = 1;	//遇到第一個不為0的數時開始印 
		if(can) printf("%d",bi[i]);
	}
	printf(" %d",cnt);
	return 0;
}
