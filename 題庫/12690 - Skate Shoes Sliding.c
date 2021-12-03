/*#include <stdio.h>
int main(){
	int n,ne=0,po=0;
	char c;
	scanf("%d",&n);
	while(getchar()!='\n');	//此處記得要把換行吃掉，不然%c會讀到換行 
	while(n){
		scanf("%c",&c);
		if(c=='L'){
			ne++;
		}else{
			po++;
		}
		n--;
	}
	printf("%d\n",ne+po+1);
	return 0;
}*/




#include <stdio.h>
int main()
{
	int n, i, l = 0, r = 0;
	char c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%c",&c);
		if(c == 'L') l++;
		else r++;
	}
	printf("%d\n",l+r+1);
	return 0;
}
