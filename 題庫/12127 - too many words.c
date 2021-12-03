/*
// getchar 快 
#include <stdio.h> 
char str[10000001];
int main(){
	char c;
	int n=0;
	while((c=getchar())!=EOF){
		str[n]=c;
		n++;
	}
	str[n]='\0';
	printf("%s",str);
	return 0;
}
*/
// scanf 慢 
/*
#include <stdio.h>
char str[10000001];
int main(){
	char c;
	int n=0;
	while(scanf("%c",&c)!=EOF){
		str[n]=c;
		n++;
	}
	str[n]='\0';
	printf("%s",str);
	return 0;
}
*/




#include <stdio.h>
int main()
{
	char c;
	while((c = getchar()) != EOF) printf("%c",c);
	return 0;
}
