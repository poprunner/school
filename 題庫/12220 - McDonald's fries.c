/*#include <stdio.h>
#define ll long long int
ll a[(int)1e6+10];
int bi(int l,int r,ll f)
{
	if(l == r) return (a[l]-f >= 0) ? l : -1;		//如果找不到傳負值 
	int m = l+(r-l)/2;
	if(a[m]-f >= 0) return bi(l,m,f);				//一定會找到序號最小而符合的 
	else if(a[m]-f < 0) return bi(m+1,r,f);
}
int main(){
	int n, k, q, i, front, back;
	ll f;
	scanf("%d%d%d",&n,&k,&q);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(q--)
	{
		scanf("%lld",&f);
		back = bi(1,k,f);				//分前後段找 
		front = bi(k+1,n,f);
		if(back > 0 && front > 0)
			if(a[back] < a[front]) printf("%d\n",n-k+back);
			else printf("%d\n",front-k);
		else if(back < 0 && front > 0) printf("%d\n",front-k);
		else if(back > 0 && front < 0) printf("%d\n",n-k+back);
		else printf("gan ni nya sai bau\n");
	}
	return 0;
}*/



#include <stdio.h>
#define ll long long int
ll a[(int)1e6+10], f;
int find(int l,int r)
{
	if(l == r) return (a[l] >= f) ? l : -1;
	int m = l + (r - l) / 2;
	if(a[m] >= f) find(l,m);
	else find(m+1,r);
}
int main()
{
	int n, k, q, i, b, c;
	scanf("%d%d%d",&n,&k,&q);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	while(q--)
	{
		scanf("%lld",&f);
		b = find(0,k-1);
		c = find(k,n-1);
		if(b == -1 && c == -1) printf("gan ni nya sai bau\n");
		else if(b == -1) printf("%d\n",c-k+1);
		else if(c == -1) printf("%d\n",b+n-k+1);
		else if(a[b] < a[c]) printf("%d\n",b+n-k+1);
		else printf("%d\n",c-k+1);
	}
	return 0;
}
