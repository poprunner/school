/* 
#include <stdio.h>				//幹幹幹請看清楚大小寫  幹失智被大小寫蠢死 
#define N 1005					//頂點最大編號到1000號 
int map[N][N];					//開二維陣列紀錄點與點之間是否有連線 0 沒連 1 有連 
int p[N];						//表示點是在 1區還是2區 
int yes = 1;					//yes = 1表是二分圖 0則不是 

void find(int row)				//找 row 列 
{								//此事能確保所有點都能被標到區域 因為所有點都連在一起 不會斷開 
	int j;

	for(j=1; j<N; j++)			//找全部的column 
		if(map[row][j] == 1)	//如果那兩點有連線 
			if(p[j] == 0)		//如果該點還沒被標區域 
			{
				p[j] = 3 - p[row];	//若另一點在1區 則賦予2 反之亦然 因此用3減 
				find(j);			//找該列 (因為能確定該列已被分類到某個區域) 
			}
			else if(p[j] == p[row])	//如果該點已被標區域 且和與之連線的點同區域 
				yes = 0;		   	//yes=0 表不會是二分圖 
}									//如果該點已被標區域 且和與之連線的點不同區域 則不做任何事 
int main()
{
	int t, m, n, i, j, a, b;
	scanf("%d", &t);   
	while(t)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)			//m 條線輸入 
		{
			scanf("%d%d", &a, &b);
			map[b][a] = 1;			//同時放在[a][b]和[b][a] 以方便查找 
			map[a][b] = 1;
		}
		
		p[a]=1;						//隨便先設一個點在1區 
		find(a);					//從該點的列開始找 
		if(yes) printf("Yes\n");	//Yes 大寫接小寫 不是全大寫 
		else printf("No\n");		//No 也是 
		//更新 
		yes = 1;					//每次做完 yes回到1 (先假設是) 
		for(i=1; i<N; i++)			//map的線清光 
			for(j=1; j<N; j++)
				map[i][j] = 0;
		for(i=1; i<N; i++)			//頂點位置清0 
			p[i] = 0;
		t--;						//t-- 
		// 
	}
	return 0;
}
*/

/*
#include <stdio.h>
#define N 1010
int line[N][N],side[N];
int yes = 1;
void check(int n,int p)
{
	int i;
	for(i=1;i<=n&&yes;i++)
	{
		if(line[p][i] == 1)
		{
			if(side[i] == 0)
			{
				side[i] = 3 - side[p];
				check(n,i);
			}
			else if(side[i] == side[p])
			{
				yes = 0;
				return;
			}
		}
	}
}
int main()
{
	int t, n, m, i, j, u, v;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			line[u][v] = 1;
			line[v][u] = 1;
		}
		side[u] = 1;
		check(n,u);
		if(yes) printf("Yes\n");
		else printf("No\n");
		
		yes = 1;
		for(i=1;i<=n;i++)
			side[i] = 0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				line[i][j] = 0;
				
		t--;
	}
	return 0;
}
*/





#include <stdio.h>
#define N 1010
int line[N][N],side[N];
int yes = 1;
void check(int p)
{
	int i;
	for(i=0;i<N&&yes;i++)
		if(line[p][i] == 1)
			if(side[i] == 0)
			{
				side[i] = 3 - side[p];
				check(i);
			}
			else if(side[i] == side[p])
				yes = 0;
}
int main()
{
	int t, m, i, j, u, v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%*d%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			line[u][v] = 1;
			line[v][u] = 1;
		}
		side[u] = 1;
		check(u);
		if(yes) printf("Yes\n");
		else printf("No\n");
		
		yes = 1;
		for(i=0;i<N;i++)
			side[i] = 0;
		for(i=0;i<N;i++)	
			for(j=0;j<N;j++)
				line[i][j] = 0;
	}
	return 0;
}
