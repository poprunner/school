/*#include <stdio.h>
int move[200005];	//標記已移動過 
int seq[100005];	//換到前面的數 
int main(){
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=m;i>=1;i--){
		scanf("%d",&seq[i]);//將要換的數按順序排列 
		move[seq[i]]=1;
	}
	for(i=1;i<=m;i++){
		if(move[seq[i]]==1){		//開印(先確認移動為1才印)	 印完後移動改2	
		//防止有數字移動超過一次而重複印出(只印最後被換到最前面的那次) 
			printf("%d\n",seq[i]);
			move[seq[i]]=2;
		}
	}
	for(i=1;i<=n;i++){		//剩下徹頭徹尾都沒被換過的全部按順序印出來 
		if(move[i]==0){
			printf("%d\n",i);
		}
	}
	return 0;
}*/




#include <stdio.h>
int hasmoved[(int)2e5+10], move[(int)1e5+10];		//已經移過	移哪些 
int main()
{
	int n, m, i;
	scanf("%d%d",&n,&m);
	for(i=m;i>=1;i--)
		scanf("%d",&move[i]);						//陣列從後紀到前 最後移的在最前面 
	for(i=1;i<=m;i++)
		if(hasmoved[move[i]] == 0)					//如果還沒被移過  
		{											//(可能被移過兩次 只算最後被移的地方)
			printf("%d\n",move[i]);					//印出 
			hasmoved[move[i]] = 1;					//表示已經被移過 (最後的位置) 
		}
	for(i=1;i<=n;i++)
		if(hasmoved[i] == 0) printf("%d\n",i);		//從未被移過的照順序印出來 
	return 0;
}
