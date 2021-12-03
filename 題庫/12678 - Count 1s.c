/*#include <stdio.h>
int acm1[1000005];
int howmany(int);
int main(){
	int i,t,a,b;
	for(i=1;i<=1000000;i++){
		acm1[i]=acm1[i-1]+howmany(i);
	}
	scanf("%d",&t);
	while(t){
		scanf("%d%d",&a,&b);
		printf("%d\n",acm1[b]-acm1[a-1]);
		t--;
	}
	return 0;
}
int howmany(int i){
	int j=0;
	while(i){
		if(i%10==1){
			j++;
		}
		i/=10;
	}
	return j;
}*/




#include <stdio.h>
long long int cnt[(int)1e6+10];
int main()
{
	int t, a, b, i, num;
	scanf("%d",&t);
	for(i=1;i<=(int)1e6;i++)
	{
		num = i;
		while(num)
		{
			if(num%10 == 1) cnt[i]++;
			num/=10;
		}
		cnt[i]+=cnt[i-1];
	}
	while(t)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cnt[b] - cnt[a-1]);
		t--;
	}
	return 0;
}
