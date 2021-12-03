/*#include <stdio.h>		//方法見最下方 
int cnt;
long long int x[105]; 	//記得要用long lnog int 因為--------------如下 
long long int y[105];
int board[105][105];
int line(int f,int m,int b){//下為斜率判斷法 (將delta y乘到對面) 
	if( (x[f]-x[m])*(y[m]-y[b]) == (y[f]-y[m])*(x[m]-x[b]) ){//只用int 這裡相乘  
		if(board[f][m]==0&&board[f][b]==0&&board[m][b]==0){  //(2*10^5)*(2*10^5)=4*10^10 會溢位 
			cnt++;											 //int 只到約 2*10^9
		}
		board[f][m]=1;
		board[f][b]=1;
		board[m][b]=1;
	}
	return 0;
}
int main(){
	int t,n,i,j,k;
	scanf("%d",&t);
	while(t){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lld%lld",&x[i],&y[i]);
		}
		for(i=0;i<n-2;i++){
			for(j=i+1;j<n-1;j++){
				for(k=j+1;k<n;k++){
					line(i,j,k);		
				}
			}
		}
		printf("%d\n",cnt);
		for(i=0;i<105;i++){		//標記矩陣歸0 
			for(j=0;j<105;j++){
				board[i][j]=0;
			}
		}
		cnt=0;					//cnt歸0 
		t--;
	}
	return 0;
}
*/
/* 

方法:
 
ex:
 1
   2 6
 7   3
   9 8 4 
    10   5
    
(4條線)

碰到三點共線時將兩兩點間畫線(標記為1) 

下次在碰到三點共線時如果其中兩點已被標計為1過 則不將線數+1 
並將其兩兩點間都標記為1以供往後參考 
若皆沒被標計過則+1 


1+1+1+1=4 條線 

  1 2 3 4 5 6 7 8 9 10
1 \ 1 1 1 1 0 0 0 0 0   
2 0 \ 1 1 1 0 0 0 0 0 
3 0 0 \ 1 1 1 0 1 0 1 
4 0 0 0 \ 1 0 0 1 1 0 
5 0 0 0 0 \ 0 0 0 0 0 
6 0 0 0 0 0 \ 0 1 0 1 
7 0 0 0 0 0 0 \ 0 1 1 
8 0 0 0 0 0 0 0 \ 1 1 
9 0 0 0 0 0 0 0 0 \ 1 
100 0 0 0 0 0 0 0 0 \ 


*/ 




#include <stdio.h>
#define ll long long int
int line[100][100];
ll x[100], y[100];
int main()
{
	int t, n, i, j, k, ans = 0;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld%lld",&x[i],&y[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				for(k=j+1;k<n;k++)
					if((y[j]-y[i])*(x[k]-x[j]) == (y[k]-y[j])*(x[j]-x[i]))
					{
						if(line[i][j] == 0 && line[i][k] == 0 && line[j][k] == 0) ans++;
						line[i][j] = 1;
						line[i][k] = 1;
						line[j][k] = 1;
					}
		printf("%d\n",ans);
		
		ans = 0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				line[i][j] = 0;
		t--;
	}
	return 0;
}
