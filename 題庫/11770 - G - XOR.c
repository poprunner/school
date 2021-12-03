#include <stdio.h>					//關鍵想法: 2進位下各個數 XOR後是與其他位獨立的 取各位數的最小 
#define ll long long int			//XOR 加總即為 全部一起的最小 XOR總和 
int a[(int)1e5+5];					//存各值之陣列 
int bi[32];							//num的二進位形式 
void find(int ith, int n, ll ori)	//找num各位置為何能使 tt 最小 
{		 //第幾位| 值個數| 與0 XOR之和 
	int i;
	ll cnt=0;						//cnt為該位數為1時與各值 XOR的和 
	
	if(ith < 0) return;				//如果已經決定完各位數 return 
	for(i=0; i<n; i++)				//計算 與該位數為1時 XOR 的和 
		cnt += (1 << ith ) ^ a[i];	// 1<<ith 表示將 1推到該位數去與各值XOR 
	if(cnt<ori)						//如果與 1 XOR < 與0 XOR
	{
		bi[ith]=1;					//則該位數應為 1 
		find(ith-1, n, ori);		//並決定下一層 
	}
	else							//同理 
	{
		bi[ith]=0;
		find(ith-1, n, ori);
	}
}
int main(){
	int n,i,num=0;			//num tt 歸0
	ll tt=0, ori=0;			//tt 歸 0是基本  ori為a[i]之和 
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		ori+=a[i];			//ori 除了是 a[i]之和 也是各值與 0 XOR 的和 
	}
	
	find(20, n, ori);		//傳 現在再處理第幾個二進位 數值個數 各值與0 XOR 的和 
	
	for(i=20; i>=0; i--)	//將bi轉回10進位形式 
	{
		num*=2;
		num+=bi[i];
	}
	
	for(i=0; i<n; i++)		//將各值與所求 num 做 XOR 並加總 
		tt += num ^ a[i];
	printf("%lld\n",tt);	//印出 
	return 0;
}
