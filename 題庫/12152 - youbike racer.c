/*#include <stdio.h>
int cp[(int)1e5+5];
int stop(int start, int end, int k, int cur)
{
	int i = start;					//將i 設為起始號碼 
	while(cp[i]-cp[start] <= k && i <= end)//當號碼間距離 <= 腳踏車距離時  
									       //&&號碼<=終點時(能成功騎到終點就不用再試了) 
		i++;						//挑戰更遠的距離直到失敗 (while遇失敗便停) 
	i--;							//失敗的前一個位置即最遠成功位置 
	if(i == start)
		return -1;					//如果發現留在原地表示失敗 傳 -1 
	if(i == end)
		return cur;					//如果到終點回傳換車數 
	stop(i, end, k, cur+1);			//還沒到終點則換車數 +1 並繼續往下騎 
}
int main(){
	int n, k, i, penalty;
	scanf("%d%d", &n, &k);
	for(i=1; i<=n; i++)				//!! i=0 為起點 0 !! <- *關鍵觀念* 
		scanf("%d", &cp[i]);
	penalty = stop(0, n, k, 0);		//換幾次腳踏車 = stop(起點號碼 終點號碼 腳踏車距離 換車數) 
	
	if(penalty == -1) printf("The Legend Falls.\n");
	else			  printf("%d\n",penalty);
	return 0;
}*/



/* 
#include <stdio.h>
int a[100010];
int main()
{
	int n, k, i, now = 0, change = 0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	i = 0;
	while(1)
	{
		while(a[now]-a[i] <= k && now <= n) now++;
		now--;
		if(now == n) break;
		if(now == i){change = -1; break;}
		else{change++; i = now;}
	}
	if(change >= 0) printf("%d\n",change);
	else printf("The Legend Falls.\n");
	return 0;
} 
*/

#include <stdio.h>
int p[(int)1e5+10];
int main()
{
	int n, k, i, now = 0, to = 0, stop = 0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	while(1)
	{
		while(p[to] - p[now] <= k && to <= n) to++;
		to--;
		if(to == now){stop = -1; break;}
		if(to == n) break;
		stop++;
		now = to;
	}
	if(stop == -1) printf("The Legend Falls.\n");
	else printf("%d\n",stop);
	return 0;
} 
