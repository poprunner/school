#include <stdio.h>
#define ll long long int
typedef struct{int f, s;}_a;			//first第一天 second第二天 
_a a[(int)1e5+5];
int cmp(const void *_x, const void *_y)	//排: 越前面第一天越便宜 越後面第二天越便宜 
{
	_a x = *(_a*)_x;
	_a y = *(_a*)_y;
	if(x.s-x.f < y.s-y.f) return 1;		//第二天比第一天貴最多者排前面
	else return 0;
}
int main(){
	int n, k, i;
	ll tt=0;
	scanf("%d%d", &n, &k);
	for(i=0; i<n; i++)
		scanf("%d",&a[i].f);
	for(i=0; i<n; i++)
		scanf("%d",&a[i].s);

	qsort(a, n, sizeof(_a), cmp);
	
	for(i=0; i<k; i++)					//第一天必買 k個 那就從第一天比第二天最便宜的開始買 
		tt+=a[i].f;
	for(i=k; i<n; i++)					//其他則選擇兩天中便宜的那個買 
	{
		if(a[i].f<a[i].s) tt+=a[i].f;
		else tt+=a[i].s;
	}
	printf("%lld\n",tt);
	return 0;
}





/*
#include <stdio.h>
#define ll long long int
typedef struct{int f, s;}_a;			//first第一天 second第二天 
_a a[(int)1e5+5];
int cmp(const void *_x, const void *_y)	//排: 越前面第一天越便宜 越後面第二天越便宜 
{
	_a x = *(_a*)_x;
	_a y = *(_a*)_y;
	if(x.s-x.f < y.s-y.f) return 1;		//第二天比第一天貴最多者排前面
	else return 0;
}
int main(){
	int n, k, i;
	ll tt=0;
	scanf("%d%d", &n, &k);
	for(i=0; i<n; i++)
		scanf("%d",&a[i].f);
	for(i=0; i<n; i++)
		scanf("%d",&a[i].s);

	qsort(a, n, sizeof(_a), cmp);
	
	for(i=0; i<k; i++)					//第一天必買 k個 那就從第一天比第二天最便宜的開始買 
		tt+=a[i].f;
	for(i=k; i<n; i++)					//其他則選擇兩天中便宜的那個買 
	{
		if(a[i].f<a[i].s) tt+=a[i].f;
		else tt+=a[i].s;
	}
	printf("%lld\n",tt);
	return 0;
}
*/ 
