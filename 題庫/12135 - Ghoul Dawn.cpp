/*#include <stdio.h>
int main(void){
	long double sum=0;
	double max=0;
	int n,k,i,j,x;
	int a[5000]={0};
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-k+1;i++){
		for(x=i;x<i+k;x++){
			sum+=a[x];
		}
		if((sum/k)>max){
			max=sum/k;
		}
		for(;x<n;x++){
			sum+=a[x];
			if((sum/(x-i+1))>max){
				max=sum/(x-i+1);
			}
		}		
		sum=0;
	}
	printf("%.3f\n",max);
	return 0;	
}*/




#include <stdio.h>
#define ll long long int
ll a[5010];
int main()
{
	int n, k, i, j, hp;
	double max = 0,avgmax = 0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&hp);
		a[i] = a[i-1] + hp;
	}
	for(i=k;i<=n;i++)
	{
		for(j=1;j-1+i<=n;j++)
			if(a[j-1+i]-a[j-1] > max) max = a[j-1+i]-a[j-1];
		if(max/i > avgmax) avgmax = max/i;
		max = 0;
	}
	printf("%.3f\n",avgmax);
	return 0;
}
