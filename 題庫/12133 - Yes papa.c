/*#include <stdio.h>			//全部他媽給我排隊站好法 
#include <string.h>
char a[100005];
char b[100005];
void rerange(int p,int len){//直接按升序排列	傳起始位置和字串長度 
	int i;					
	char tmp;
	if(len%2==0){			//如果是偶數	(是奇數直接軟掉 送出去直接比較) 
		if(len/2%2==0){		//如果除2是偶數 遞迴至下層(代表還有更基本單元) 
			rerange(p,len/2);
			rerange(p+len/2,len/2);
		}
		if(strncmp(a+p,a+p+len/2,len/2)>0){//如果前半段比後半段大 前後交換 此為交換a 
			for(i=0;i<len/2;i++){
				tmp=a[i+p];
				a[i+p]=a[i+p+len/2];
				a[i+p+len/2]=tmp;
			}
		}
		if(strncmp(b+p,b+p+len/2,len/2)>0){//此為交換b 
			for(i=0;i<len/2;i++){
				tmp=b[i+p];
				b[i+p]=b[i+p+len/2];
				b[i+p+len/2]=tmp;
			}
		}
	}
}
int main(){
  	scanf("%s",a);
  	scanf("%s",b);
  	rerange(0,strlen(a)); 
  	if(strcmp(a,b)==0){		//直接按升序排列後比較 
  		printf("YES\n");
	}else{
		printf("NO\n"); 
	}
  	return 0;
}*/


/*
#include <stdio.h>
#include <string.h>
char a[(int)(1e5+10)],b[(int)(1e5+10)];//開陣列 
int eq(int pa,int pb,int l) //ap:a's position  	bp:b's position	  l:length
{
	if(l%2==1)								//if odd 不可切 
		return (strncmp(a+pa,b+pb,l) == 0);	//比較是否相等 如果一樣回傳1 否則為0 
	if(eq(pa    ,pb    ,l/2) && eq(pa+l/2,pb+l/2,l/2)) return 1;//若可切分兩種
	if(eq(pa+l/2,pb    ,l/2) && eq(pa    ,pb+l/2,l/2)) return 1;//如果皆相等則回傳1 
	return 0;													//否則為0 
}
int main()
{
	scanf("%s",a);
	scanf("%s",b);
	if( eq(0,0,strlen(a)) ) printf("YES\n");//如果為1則表相等 YES 
	else printf("NO\n");					//否則為 NO 
	return 0;
}
*/




#include <stdio.h>
#include <string.h>
char a[(int)1e5+10], b[(int)1e5+10];
int eq(int ap,int bp,int len)
{
	if(len%2 == 1) return !strncmp(a+ap,b+bp,len);
	else 
		return 
			(eq(ap,bp,len/2) && eq(ap+len/2,bp+len/2,len/2)) 
			||
			(eq(ap+len/2,bp,len/2) && eq(ap,bp+len/2,len/2))
		;
}
int main()
{
	scanf("%s%s",a,b);
	if( eq(0,0,strlen(a)) ) printf("YES\n");
	else printf("NO\n");
	return 0;
}
