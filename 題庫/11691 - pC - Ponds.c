/*
#include <stdio.h>
#include <ctype.h>
char map[1005][1005];
int cnt;
void find(int i,int j,int m,int n,int mode){ //mode1 表示正常掃圖計算  
											 //mode0 表示遇到河時直接把該河填滿 以避免重複計算 
	if( i<0 || i>=m || j<0 || j>=n ){
		return;
	}
	if(map[i][j]=='~'){		//若找到河則cnt++並把該河填滿 
		if(mode){
			cnt++;
		}
		map[i][j]='.';
		find(i-1,j,m,n,0);
		find(i,j-1,m,n,0);
		find(i+1,j,m,n,0);
		find(i,j+1,m,n,0);
	}
	if(mode){				//填完後用mode1往下繼續掃圖 
		if(j==n-1){
			find(i+1,0,m,n,1);
		}else{
			find(i,j+1,m,n,1);
		}
	}
}
int main(){
 	int m,n,i,j;
 	scanf("%d%d",&m,&n);
 	for(i=0;i<m;i++){
 		scanf("%s",map[i]);	//用%s避免許多麻煩事 如換行等	
	}
	find(0,0,m,n,1);
	printf("%d\n",cnt);
 	return 0;
 }
 */
 
 
#include <stdio.h>
char map[1005][1005];
void find(int i,int j,int m,int n){
	if( i<0 || i>=m || j<0 || j>=n ) return;
	if(map[i][j] == '~'){
		map[i][j] = '.';
		find(i-1,j,m,n);
		find(i,j-1,m,n);
		find(i+1,j,m,n);
		find(i,j+1,m,n);
	}
}
int main(){
 	int m, n, i, j, cnt = 0;
 	scanf("%d%d",&m,&n);
 	for(i=0;i<m;i++) scanf("%s",map[i]);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(map[i][j] == '~'){find(i,j,m,n); cnt++;}
	printf("%d\n",cnt);
 	return 0;
 }
