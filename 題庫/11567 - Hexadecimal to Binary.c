/*#include <stdio.h>
int main(){
	int x,y;
	int bi[32];
	scanf("%x %x",&x,&y);
	x+=y;					//將變數和放在x 
	for(y=0;;y++){			//拆出2進位放入陣列 
		if(x==0){
			break;
		}
		bi[y]=x%2;
		x/=2;
	}
	for(x=y-1;x>=0;x--){	//照正確順序(反向)印出來 
		printf("%d",bi[x]);
	}
	return 0;
}*/




#include <stdio.h>
int main()
{
	int a, b, i = 0, sum, bi[100];
	scanf("%x%x",&a,&b);
	sum = a+b;	
	do
	{
		bi[i] = sum%2;
		sum/=2;
		i++;
	}while(sum);
	for(i--;i>=0;i--)
		printf("%d",bi[i]);	
	return 0;
}
