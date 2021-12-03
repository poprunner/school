/*#include <stdio.h>
int wh[26];			//標註1~25各放在哪裡 
int choose[25];		//同學選的數列 
int mark[5][5];		//標記棋盤已確認是否有連線 
int check(int,int);	//一直往下比對是否贏  沒則回傳0 
int win(void);		//找是否贏 
int main(){
	int i,j,k,ps,t,n,rst;
	for(i=0;i<5;i++){			//讀取1~25各放在哪裡
		for(j=0;j<5;j++){		//此處並非值接案號輸入 
			scanf("%d",&ps);	//而是透過輸入是幾號  將該號之值填入位置序號 
			wh[ps]=10*i+j;		//位置序號:列*10+行  保證其不互相影響 
		}
	}
	scanf("%d",&t);				//輸入有幾筆要測 
	for(k=1;k<=t;k++){			//循環 
		scanf("%d",&n);			//數列有幾個數 
		for(i=0;i<n;i++){		//依序存進choose 
			scanf("%d",&choose[i]);
		}
		rst=check(0,n);			//紀錄回傳值  表是第幾個數時就能賓果  0則表示無法賓果 
		if(rst==0){				//若為0  表示沒找到 
			printf("Case #%d: Not yet \\(^o^)/\n",k);//印反斜線記得要打 \\ (跳脫字元用法) 
		}else{					//否則印該結果 
			printf("Case #%d: %d\n",k,rst);
		}
		for(i=0;i<5;i++){		//每次檢查完都要將mark歸零 
			for(j=0;j<5;j++){
				mark[i][j]=0;
			}
		}
	}
	return 0;
}
int check(int flag,int n){
	if(flag==n){			//如果已經檢查超過此序列長度時  表沒賓果  回傳0 
		return 0;
	}
	mark[wh[choose[flag]]/10][wh[choose[flag]]%10]=1;//將該數位置mark為1 
	if(win()){				//如果贏了 
		return flag+1;		//回傳檢查到第幾個  要+1因為flag從0開始 
	}else{
		check(flag+1,n);	//否則繼續往下個數 
	}
}
int win(void){
	int i,j,rc=0;
	for(i=0;i<5;i++){		//5列都要檢查	
		for(j=0;j<5;j++){	//檢查是否有列賓果 
			if(mark[i][j]){
				rc++;		//mark為1就+1 
			}
		}
		if(rc==5){			//若該列5個都選過  回傳1表他已經贏了 
			return 1;
		}else{
			rc=0;			//否則歸0找下種 
		}
	}
	
	for(j=0;j<5;j++){		//改檢查行  原理同列檢查法 
		for(i=0;i<5;i++){
			if(mark[i][j]){
				rc++;
			}
		}
		if(rc==5){
			return 1;
		}else{
			rc=0;
		}
	}
	
	for(i=0;i<5;i++){		//檢查左上右下對角線 
		if(mark[i][i]){
			rc++;
		}
	}
	if(rc==5){
		return 1;
	}else{
		rc=0;
	}
	
	for(i=0;i<5;i++){		//檢查右上左下對角線 
		if(mark[i][4-i]){
			rc++;
		}
	}
	if(rc==5){
		return 1;
	}else{
		rc=0;
	}
	return 0;
}*/





#include <stdio.h>
int board[5][5], bingo[5][5];
int win(void)
{
	int i, j, dot = 0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			if(bingo[i][j]) dot++;
		if(dot == 5) return 1;
		dot = 0;
	}
	for(j=0;j<5;j++)
	{
		for(i=0;i<5;i++)
			if(bingo[i][j]) dot++;
		if(dot == 5) return 1;
		dot = 0;
	}
	for(i=0;i<5;i++)
		if(bingo[i][i]) dot++;
	if(dot == 5) return 1;
	dot = 0;
	for(i=0;i<5;i++)
		if(bingo[i][4-i]) dot++;
	if(dot == 5) return 1;
	dot = 0;
	return 0;
}
int main()
{
	int i, j, k, l, t, h, w, lose = 1, nowon = 1;//h有幾個數 w幾號 
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&board[i][j]);
	scanf("%d",&t);
	for(l=1;l<=t;l++)
	{
		scanf("%d",&h);
		for(i=1;i<=h;i++)
		{
			scanf("%d",&w);
			for(j=0;j<5;j++)
				for(k=0;k<5;k++)
					if(w == board[j][k]) bingo[j][k] = 1;
			if(win()&&nowon){printf("Case #%d: %d\n",l,i); lose = 0; nowon = 0;}			
		}
		if(lose) printf("Case #%d: Not yet \\(^o^)/\n",l);	//很重要!! 反斜線要印時要兩條 \\ 
		
		lose = 1;
		nowon = 1;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				bingo[i][j] = 0;
	}
	return 0;
}
