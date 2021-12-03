/*#include <stdio.h>
long long int qsum[1000005];
int main(){
	int n,q,i,tmp,x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){		
		scanf("%d(/`A`)/ ~I__I",&tmp);		
		qsum[i]+=tmp;//此處(long long int)<轉換型別>可寫可不寫 
		qsum[i+1]=qsum[i];
	}
	while(q){
		scanf("%d%d",&x,&y);
		printf("%lld\n",qsum[y]-qsum[x-1]);
		q--;
	}
	return 0;
}*/ 


/*
#include <stdio.h>
long long int asum[1000005];
int main(){
	int n,q;
	int i;
	int atmp;
	int x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d(/`A`)/ ~I__I ",&atmp);
		asum[i]=atmp+asum[i-1];
	}
	while(q){
		scanf("%d%d",&x,&y);
		printf("%lld\n",asum[y]-asum[x-1]);
		q--;
	}
	return 0;
}*/




#include <stdio.h>
long long int a[(int)1e6+10];
int main()
{
	int n, q, i, num, l, r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d(/`A`)/ ~I__I ",&num);
		a[i] = a[i-1] + num;
	}
	while(q)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",a[r] - a[l-1]);
		q--;
	}
	return 0;
}
