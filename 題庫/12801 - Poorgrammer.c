#include <stdio.h>
int a[(int)2e5+10], n;
int code(int day)
{
	int i, cnt = 0, p;
	for(i=0;i<n;i++)
	{
		p = i / day;
		if(a[i] - p > 0) cnt += (a[i] - p);
	}
	return cnt;
}
int main()
{
	int t, m, i, l, r, day;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		l = 1; r = n;
		while(l < r)
		{
			day = l + (r - l) / 2;
			if(code(day) >= m) r = day;
			else l = day + 1;
		}
		if(code(r) >= m) printf("%d\n",r);
		else printf("-1\n");
	}
	return 0;
}

// accepted (4/6)
/*
#include <stdio.h>
#include <stdlib.h>
#define ll long long int
ll a[(int)2e5+10], n;
int cmp(const void* a,const void* b)
{
	int c = *(int*)a;
	int d = *(int*)b;
	return d-c;
}
ll code(int day)
{
	int i, p;
	ll cnt =0;
	for(i=0;i<n;i++)
	{
		p = i / day;
		if(a[i] - p > 0) cnt += (a[i] - p);
	}
	return cnt;
}
int main()
{
	int t, i, l, r, day;
	ll m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		l = 1; r = m;
		while(1)
		{
			if(r<=l) break;
			day = l + (r - l) / 2;
			if(code(day) > m) r = day;
			else l = day + 1;
		}
		if(code(r) > m) printf("%d\n",r);
		else printf("-1\n");
	}
	return 0;
}
*/
