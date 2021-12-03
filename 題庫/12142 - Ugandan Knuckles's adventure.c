/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[100][1000];
int cmp(const void *_a,const void *_b)		//關鍵: 比較 ab ba 的大小 
{											//這樣就不用擔心 a b 之間字串長度不同的比較問題了 
	char *a = (char*)_a;					//記得只要一個*號 
	char *b = (char*)_b;					//因為 _a 是傳陣列的指標 每1000格char傳一個進來 
	char ab[2000], ba[2000];
	strcpy(ab,a); strcat(ab,b);
	strcpy(ba,b); strcat(ba,a);
	return -strcmp(ab,ba);					//前面大傳正值 後面大傳負值 
}
int main()
{	
	int n, i;
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<n;i++) scanf("%s",a[i]);
		qsort(a,n,sizeof(char[1000]),cmp);
		for(i=0;i<n;i++) printf("%s",a[i]);
		printf("\n");
	}
	return 0;
}*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[100][1000];
int cmp(const void *_a,const void *_b)
{
	char ab[2000], ba[2000];
	char *a = (char*)_a;
	char *b = (char*)_b;
	strcpy(ab,a), strcat(ab,b);
	strcpy(ba,b), strcat(ba,a);
	return strcmp(ba,ab);
}
int main()
{
	int n, i;
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<n;i++) scanf("%s",str[i]);
		qsort(str,n,sizeof(str[0]),cmp);
		for(i=0;i<n;i++) printf("%s",str[i]);
		printf("\n");
	}
	return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[100][1010];
int cmp(const void *a,const void *b)
{
	char e[2020], f[2020];
	char* c = (char*)a;
	char* d = (char*)b;
	strcpy(e,c), strcat(e,d);
	strcpy(f,d), strcat(f,c);
	return strcmp(f,e);
}
int main()
{
	int n, i;
	while(scanf("%d",&n) != EOF)
	{
		for(i=0;i<n;i++) scanf("%s",str[i]);
		qsort(str,n,sizeof(str[0]),cmp);
		for(i=0;i<n;i++) printf("%s",str[i]);
		printf("\n");
	}
	return 0;
}
*/
