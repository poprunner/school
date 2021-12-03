#include <stdio.h>
typedef struct
{
	char name[25];
	int grade;
}record;
record r[100005];
int cmp(const void *_a,const void *_b)
{
	record a = *(record*)_a;
	record b = *(record*)_b;
	return a.grade < b.grade;
}
int main()
{
	int n, i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s%d",r[i].name,&(r[i].grade));
	qsort(r,n,sizeof(record),cmp);
	for(i=0;i<n;i++)
		printf("%s\n",r[i].name);
 	return 0;
}
