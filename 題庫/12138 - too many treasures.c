/*#include <stdio.h>
long long int a[1000005];
int main(){
	int n,q,tmp,i,l,m;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&tmp);
		if(tmp>0){
			a[i]=a[i-1]+tmp;
		}else{
			a[i]=a[i-1];
		}
	}
	while(q){
		scanf("%d%*d%d",&l,&m);
		printf("%lld\n",a[l-1+m]-a[l-1]);
		q--;
	}
	return 0;
}*/




#include <stdio.h>
long long int a[(int)1e6+10]; 
int main()
{
	int n, q, l, m, i, num;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		a[i] = a[i-1];
		if(num > 0) a[i]+=num;
	}
	while(q)
	{
		scanf("%d%*d%d",&l,&m);
		printf("%lld\n",a[l+m-1] - a[l-1]);
		q--;
	}
	return 0;
}
