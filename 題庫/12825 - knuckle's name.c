#include <stdio.h>
int n, a[2020], visited[2020];				//a在2^0處 b在2^1處 z在2^25處 依此類推 
void dfs(int now,int pa)					//若該字串有該字母 則其代表數在該字母二進位位置為1 
{
	int i, j;
	visited[now] = 1;
	for(i=0;i<n;i++)
	{
		if(visited[i]) continue;
		if(a[i] & a[now]) dfs(i,now);		//利用比特運算 都有同一字母則值大於0 
	}
}
int main()
{
	int t, i, ans;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		scanf("%d",&n);
		while(getchar() != '\n');
		for(i=0;i<n;i++)
			while((c = getchar()) != '\n')	//若該字母位置的位元尚為0 將其改為1 
				if( (a[i] & (1<<(c-'a'))) == 0) a[i] += 1<<(c-'a');
		for(i=0;i<n;i++)
			if(visited[i] == 0){dfs(i,i); ans++;}
		printf("%d\n",ans);
		
		for(i=0;i<2020;i++)
		{
			a[i] = 0;
			visited[i] = 0;
		}
	}
	return 0;
}
