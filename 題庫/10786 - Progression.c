/*#include <stdio.h>
int main(){
	int b,c,d;
	scanf("%d%d%d",&b,&c,&d);
	if(b*d==c*c){
		printf("%d %d",b/(c/b),d*(c/b));
	}else if(b+d==2*c){
		printf("%d %d",b-(c-b),d+(c-b));
	}
	return 0;
}*/




#include <stdio.h>
int main()
{
	int b, c, d;
	scanf("%d%d%d",&b,&c,&d);
	if(b+d == 2*c) printf("%d %d",b-(c-b),d+(c-b));
	else printf("%d %d",b/(c/b),d*(c/b));
	return 0;
}
