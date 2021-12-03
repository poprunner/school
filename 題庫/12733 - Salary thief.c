//範圍根本不是1000000  a[1936385]才AC	測資最大值可能為1936384 

#include <stdio.h>
#include <string.h>
char a[2000000];				//存序列 
long long int cnt;
int main(void){
	int n,k,i,mode=0,j,p,can=1;	//n幾輪測資	k切幾次 i(for) j(for) p紀錄字串長度	
								//mode(cnt)計算模式 can複製數列開關 
	scanf("%d",&n);				//幾輪測資 
	while(n){
		scanf("%d",&k);			//切到第幾位 
		scanf("%s",a);			//初始數列 
		cnt=strlen(a);			//先將初始數列長度計下 
		for(i=0;i<k;i++){		//跑k次	'1'的話甚麼都不用做 
			if(a[i]=='2'){		//若為 '2' 複製後段數列到尾巴一次 
				if(can){		//can表示還需將序列複製 直到大於k就不用印 因為用不到了 
					p=strlen(a);
					for(j=0;j<=p-i-2;j++){//複製p-1-i個字 
						if(p+j>=k){
							can=0;//若末位大於k k改為0 不用再複製了 
							break;
						}
						a[p+j]=a[i+1+j];
					}
					a[p+j]='\0';
				}
				if(mode==0){	//如果還沒大到需取餘數	直接加上長度 
					cnt+=(cnt-i-1);
					if(cnt/1000000007>0){//若已經大過10^9+7	開始取餘數並切換至mode1 
						cnt%=1000000007;
						mode=1;
					}
				}else if(mode==1){
					cnt=(1000000007-(i+1)+cnt+cnt)%1000000007;//mode1為此算法 
				}												
				//算法:((10^9+7) - 切的位子 + cnt)->增加多少位數
				//		((10^9+7) - 切的位子 + cnt) + cnt->加上餘數
				//		 (((10^9+7) - 切的位子 + cnt) + cnt)%10^9+7->再取餘數 
			}else if(a[i]=='3'){//與'2'相似 只差在再多複製一次到行末 
				if(can){
					p=strlen(a);
					for(j=0;j<=p-i-2;j++){
						if(p+j>=k){
							can=0;
							break;
						}
						a[p+j]=a[i+1+j];
					}
					a[p+j]='\0';
					for(j=0;j<=p-i-2;j++){
						if(2*p-i-1+j>=k){
							can=0;
							break;
						}
						a[2*p-i-1+j]=a[i+1+j];
					}
					a[2*p-i-1+j]='\0';
				}
				if(mode==0){
					cnt+=2*(cnt-i-1);
					if(cnt/1000000007>0){
						cnt%=1000000007;
						mode=1;
					}
				}else if(mode==1){
					cnt=((1000000007-(i+1)+cnt)*2+cnt)%1000000007;
				}
			}
		}
		printf("%lld\n",cnt);	//印出結果 
		can=1;					//can改回原本 
		mode=0;					//mode改回原本 
		n--;
	}
	return 0;
}
