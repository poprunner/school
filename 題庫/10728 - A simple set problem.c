/*#include <stdio.h>
int main(){
	int n,x,y,z;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	printf("%d %d",x+y+z-n,x-(x+y+z-n));
	return 0;
}*/




#include <stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d %d",b+c-(a-d),b-(b+c-(a-d)));
	return 0;
}
