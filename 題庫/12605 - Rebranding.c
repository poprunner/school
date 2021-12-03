#include<stdio.h>/*200000*50*2==2E7千萬次量級	優於百億次量級的純遞迴*/
#include<string.h>
char str[300000];
int haschange[300000];
int map[26];
int main(){
	int i,j,len,num;
	char u,v;
	scanf("%d%d",&len,&num); 
	scanf("%s",str);
	//填map 	0~25 各自代表 a~z 
	for(i=0;i<26;i++){
		map[i]=i;
	}
	while(num) {								/*200000*/
		//讀要交換的字母 
		while( getchar() != '\n' );
		u=getchar();
		getchar();
		v=getchar();
		//使 a~z 使用 0~25 表達 
		u-='a';
		v-='a';
		//map 的 a~z 將被接下來的字母取代... 
		for(i=0;i<26;i++){						/*26*2*/
			if(map[i]==u){
				map[i]=v;
			}else if(map[i]==v){
				map[i]=u;
			}
		}
		//此輪map設置完  進下輪 
		num--;//扣打-1
	}
	//map設完 作用於陣列
	for(i=0;i<26;i++){//從a換到z 				/*26*/
		for(j=0;j<len;j++){						/*200000*/
			if( str[j]==i+'a' && haschange[j]==0 ){//如果該位置為該字母 && 還沒變完成 
				str[j]=map[i]+'a';//a要加回來 數字才能變回字母 
				haschange[j]++;//代表已變完成 
			}
		}
	} 
	printf("%s\n",str);//印出來 
	return 0;
}
