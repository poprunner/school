/*#include <stdio.h>
int main(){
	float f;
	int i,k;
	while(scanf("%f",&f)!=EOF){				//不能直接轉型別 值會變		要轉指標型別內部值才不會變 
		k=*(int*)&f;	//指標型別要記得加 *
		for(i=sizeof(float)*8-1;i>=0;i--){	//轉成 int 後便能用位元運算求10值了 (float無法) 
			if( k & 1<<i )
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}*/



/*
#include <stdio.h>
int main()
{
	float f;
	int x, i;
	while(scanf("%f",&f) != EOF)
	{
		x = *(int*)&f;
		for(i=sizeof(float)*8-1;i>=0;i--)
			printf("%c",(1<<i & x) ? '1' : '0');
		printf("\n");
	}
	return 0;
}
*/

#include <stdio.h>
int main()
{
	float x;
	unsigned int u;
	int i;
	while(scanf("%f",&x) != EOF)
	{
		u = *((unsigned int*)&x);
		for(i=31;i>=0;i--) printf("%d",(u & (1 << i)) ? 1 : 0);
		printf("\n");
	}
	return 0;
}
