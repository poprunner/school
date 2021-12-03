#include <stdio.h>
int l[5000], r[5000], section[5010], hasout = -1;//左位置 右位置 每個位置有幾個守衛守護 被淘汰的守衛 
void out(int q)							//記得要-1不然一開始為0的守衛就會被當成ont的 
{
	int i, j, cnt = 0, min = 5010, minp;// i j for用 cnt該守衛獨守幾塊地 min最少獨佔的地 minp該守衛是誰 
	for(i=0;i<q;i++)					//所有守衛都輪一次 
	{
		if(i != hasout)					//如果該守衛未被out 
		{
			for(j=l[i];j<=r[i];j++)		//從最左檢查到最右 
				if(section[j] == 1) cnt++;//總共獨守幾塊地 
			if(cnt < min)				//如果該守衛獨守最少塊地 
			{
				min = cnt;				//將min改為地數 
				minp = i;				//記注是哪位守衛 
			}
			cnt = 0;					//查下位守衛時cnt記得歸0 
		}
	}
	for(i=l[minp];i<=r[minp];i++) section[i]--;//將該守衛之地減掉 
	hasout = minp;						//記下該守衛已經out 
}
int main()
{
	int t, n, q, i, j, len = 0;					//len記得歸0 
	scanf("%d",&t);
	while(t)
	{
		scanf("%d%d",&n,&q);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			for(j=l[i];j<=r[i];j++) section[j]++;//記完左右後把那些地都+1表示多一個守衛在守那塊地 
		} 
		out(q);									//淘汰 
		out(q);									//淘汰 
		for(i=1;i<=n;i++)
			if(section[i]>0) len++;				//計算剩下有守的地數  有歸0 len++才不會出問題 
		printf("%d\n",len);						//印出 
		
		for(i=1;i<=n;i++) section[i] = 0;		//記地陣列記得歸0 
		len = 0;								//len也要歸0 
		t--;
	}
	return 0;
}


// 
/*
#include <stdio.h>
int l[5000], r[5000], section[5010], hasout0 = -1, hasout1 = -1;//左位置 右位置 每個位置有幾個守衛守護 被淘汰的守衛 
void out(int q,int x)							//記得要-1不然一開始為0的守衛就會被當成ont的 
{
	int i, j, cnt = 0, min = 5010, minp;// i j for用 cnt該守衛獨守幾塊地 min最少獨佔的地 minp該守衛是誰 
	for(i=0;i<q;i++)					//所有守衛都輪一次 
	{
		if(i != hasout0 && i != hasout1)					//如果該守衛未被out 
		{
			for(j=l[i];j<=r[i];j++)		//從最左檢查到最右 
				if(section[j] == 1) cnt++;//總共獨守幾塊地 
			if(cnt < min)				//如果該守衛獨守最少塊地 
			{
				min = cnt;				//將min改為地數 
				minp = i;				//記注是哪位守衛 
			}
			cnt = 0;					//查下位守衛時cnt記得歸0 
		}
	}
	for(i=l[minp];i<=r[minp];i++) section[i]--;//將該守衛之地減掉 
	if(x == 0)hasout0 = minp;						//記下該守衛已經out 
	if(x == 1)hasout1 = minp; 
}
int main()
{
	int t, n, q, i, j, len = 0;					//len記得歸0 
	scanf("%d",&t);
	while(t)
	{
		scanf("%d%d",&n,&q);
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			for(j=l[i];j<=r[i];j++) section[j]++;//記完左右後把那些地都+1表示多一個守衛在守那塊地 
		} 
		out(q,0);									//淘汰 
		out(q,1);									//淘汰 
		out(q,2);	
		for(i=1;i<=n;i++)
			if(section[i]>0) len++;				//計算剩下有守的地數  有歸0 len++才不會出問題 
		printf("%d\n",len);						//印出 
		
		for(i=1;i<=n;i++) section[i] = 0;		//記地陣列記得歸0 
		len = 0;								//len也要歸0 
		t--;
	}
	return 0;
}
*/
