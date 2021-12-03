/*#include<stdio.h>
int cnt;
void fac(int i){
	int j;
	for(j=1;j*j<i;j++){
		if(i%j==0){
			cnt+=2;
		}
	}
	if(j*j==i)
		cnt++;
	//printf("%d\n",cnt);
}
int main(void){
	int n,l,r,max=0,maxnum=0,i;
	scanf("%d",&n);
	while(n){
		scanf("%d%d",&l,&r);
		for(i=l;i<=r;i++){
			fac(i);
			if(cnt>max){//如果因數個數>max 
				max=cnt;//因數個數給max 
				maxnum=i;//該數字計錄至maxnum
			}
			cnt=0;//因數計數歸零 
		}
		printf("%d\n",maxnum);
		max=0;
		maxnum=0;
		n--;
	}
	return 0;
} */




#include <stdio.h>
int factor(int m)
{
	int i, cnt = 0;
	for(i=1;i*i<m;i++)
		if(m%i == 0) cnt+=2;
	if(i*i == m) cnt++;
	return cnt;
}
int main()
{
	int t, l, r, i, fac, max = 0, maxnum;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d%d",&l,&r);
		for(i=l;i<=r;i++)
		{
			fac = factor(i);
			if(fac > max){maxnum = i; max = fac;}
		}
		printf("%d\n",maxnum);
		
		max = 0;
		t--;
	}
	return 0;
}
