/*	TLE
//對稱法 時間/2 
#include <stdio.h>
int qc[14];
int tt;
void print(int n){
	int i,j;
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			printf("%c",(qc[j]==i) ? '@' : '-');
		}
		printf("\n");
	}
	printf("\n");
}
int can(int r,int c){
	int i;
	for(i=0;i<r;i++){
		if(qc[i]-c==0||qc[i]-c==r-i||qc[i]-c==i-r){
			return 0;
		}
	}
	return 1;
}
void find(int r,int n){
	if(r==n){
		tt++;
		print(n);
		return;
	}
	int i;
	for(i=0;i<n;i++){
		if(can(r,i)){
			qc[r]=i;
			find(r+1,n);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	find(0,n);
	printf("%d\n",tt);
	return 0;
}
*/
/*
#include <stdio.h>
int ttx,tto;
int qc[14];
void findx(int,int);
void findo(int,int);
int can(int,int);
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("1\n");
	}else if(n%2==0){
		findx(0,n);
		printf("%d\n",ttx*2);
	}else{
		findx(0,n);
		findo(0,n);
		printf("%d\n",ttx*2+tto);
	}
	return 0;
}
void findx(int r,int n){
	int i;
	if(r==0){
		for(i=0;i<n/2;i++){
			qc[r]=i;
			findx(r+1,n);
		}
	}else if(r<n-1){
		for(i=0;i<n;i++){
			if(can(r,i)){
				qc[r]=i;
				findx(r+1,n);
			}
		}
	}else{
		for(i=0;i<n;i++){
			if(can(r,i)){
				ttx++;
			}
		}
	}
}
void findo(int r,int n){
	int i;
	if(r==0){		
		qc[r]=n/2;
		findo(r+1,n);		
	}else if(r<n-1){
		for(i=0;i<n;i++){
			if(can(r,i)){
				qc[r]=i;
				findo(r+1,n);
			}
		}
	}else{
		for(i=0;i<n;i++){
			if(can(r,i)){
				tto++;
			}
		}
	}
}
int can(int r,int c){
	int i;
	for(i=0;i<r;i++){
		if(qc[i]-c==0||qc[i]-c==r-i||qc[i]-c==i-r){
			return 0;
		}
	}
	return 1;
}
*/


/* 
//記錄行是否用過法 
#include <stdio.h>
int q[14],unuse[14];//加一個unuse 來記錄該行是否已有皇后 有的話直接去掉 就不用can慢慢判斷了 
int ans;
int can(int r,int c)
{
	int i;
	for(i=0;i<r;i++)
		if(q[i]-c==0 || q[i]-c==r-i || q[i]-c==i-r) return 0;
	return 1;
}
void displace(int n,int r)
{
	int i;
	if(r == n){ans++; return;}
	for(i=0;i<n;i++)
	{
		if(unuse[i])
			if(can(r,i))
			{
				q[r] = i;
				unuse[i] = 0;
				displace(n,r+1);
				unuse[i] = 1;
			}
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) unuse[i] = 1;
	displace(n,0);
	printf("%d\n",ans);
	return 0;
} 
*/ 



/*
#include <stdio.h>
int cnt;
int u[30], l[30], r[30];//開30格是為了能夠塞進 [13-0+13] = [13+13] = 26 這個數字(至少開27格) 
void q(int row,int n)	// 正上方col一樣 左斜排row-col一樣 右斜排row+col一樣  
{
	int i;
	if(row == n){cnt++; return;}
	for(i=0; i<n; i++)
		if(u[i] == 0 && l[row-i+13] == 0 && r[row+i] == 0)	//左斜排+13是為了 
															//[0][13]處能從0開始(0-13+13=0) 
		{
			u[i] = 1;
			l[row-i+13] = 1;
			r[row+i] = 1;
			q(row+1, n);
			u[i] = 0;
			l[row-i+13] = 0;
			r[row+i] = 0;
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	q(0, n);
	printf("%d\n",cnt);
	return 0;
}
*/




#include <stdio.h>
int ans, l[30], m[14], r[30];
void q(int i,int n)
{
	if(i == n){ans++; return;}
	int j;
	for(j=0;j<n;j++)
	{
		if(l[i-j+13] == 0 && m[j] == 0 && r[i+j] == 0)
		{
			l[i-j+13] = 1;
			m[j] = 1;
			r[i+j] = 1;
			q(i+1,n);
			l[i-j+13] = 0;
			m[j] = 0;
			r[i+j] = 0;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	q(0,n);
	printf("%d\n",ans);
	return 0;
}
