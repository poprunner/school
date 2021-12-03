/*#include <stdio.h>			//思路:先將數列用升序排列 一個個往後推移加總 直到達標 
int a[20];
int cnt=0;
void find(int flag,int n,int r){//flag目前用到第幾個數 n總共幾個數 r距離達標剩多少 
	int i;
	for(i=flag;i<n;i++){		//從flag輪到最後一個數 
		if(r-a[i]>0){
			find(i+1,n,r-a[i]);	//i+1因為此數已用過 下個遞迴要+1 
		}else if(r-a[i]==0){
			cnt++;
		}else{					//如果已超過標準 直接return 不用繼續跑下去 因為接下來的數只會更大
								//就算跑也一定超標 
			return;
		}
	}
}
int main(){
	int n,k,i,j,buf;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){			//泡排 
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				buf=a[j];
				a[j]=a[j+1];
				a[j+1]=buf;
			}
		}
	}
	find(0,n,k);				//找 
	printf("%d\n",cnt);
	return 0;
}*/



/*
#include <stdio.h>
int n,k,a[20];
int ans;
void rec(int ai,int sum)//採枚舉法enumerate  因為只有20個數不會TLE 
{		//第幾個數  目前總和 
	if(sum == k){ans++; return;}//若總和為目標 ans++ 並return 因為再加只會超過 
								//且能擋掉下個輪迴不取的重複計數 
	if(ai == n) return;			//若ai已經超過所有總數的標號時 return 因為後面沒數字了 
	rec(ai+1,sum+a[ai]);		//枚舉 此數字取 sum+a[ai] 
	rec(ai+1,sum);				//枚舉 此數字不取 sum不加 
}
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	rec(0,0);
	printf("%d\n",ans);
	return 0;
}
*/




#include <stdio.h>
int ans, n, k, a[20];
void eq(int i,int sum)
{	
	if(sum == k){ans++; return;}
	if(i == n) return;
	eq(i+1,sum+a[i]);
	eq(i+1,sum);
}
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	eq(0,0);
	printf("%d\n",ans);
	return 0;
}
