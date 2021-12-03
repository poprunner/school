#include <stdio.h>
#define ll long long int
int a[8][8], used[8];								//存行列式  存該行是否已被用過 
ll det(int i,int n)									//共n列  現在在第幾列 
{	
	if(i == n) return 1;							//如果已是0階行列是回傳1(傳回一階能直接乘係數) 
	int j, rj = 0;									//處於第幾行  在子矩陣中真正位於第幾行 
	ll val = 0;										//此階行列式值 先歸0 
	for(j=0;j<n;j++)
		if(used[j] == 0)							//如果該行還沒被用 
		{
			used[j] = 1;							//該行標註為已用 
			if(rj%2 == 0) val += det(i+1,n)*a[i][j];//如果在偶數行 C=+M / C*Aij=MAij
			else val -= det(i+1,n)*a[i][j];			//奇數行 C=-M / C*Aij=-MAij 
			used[j] = 0;							//改回0 以讓別種路徑也能使用 
			rj++;									//子矩陣行數加1 
		}
	return val;										//回傳值 
}
int main()
{
	int n, i, j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);			//輸入 
	printf("%lld\n",det(0,n));				//印出 
	return 0;
}
