/*
#include <stdio.h>
int cnt,p[10];
int can(int i,int r){
	int j;
	for(j=0;j<r;j++){
		if(p[j]-i==0||p[j]-i==j-r||p[j]-i==r-j){
			return 0;
		}
	}
	return 1;
}
void q(int r,int n){
	int i;
	if(r==n){
		cnt++;
	}
	for(i=0;i<n;i++){
		if(can(i,r)){
			p[r]=i;
			q(r+1,n);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	q(0,n);
	printf("%d",cnt);
	return 0;
}
*/ 

#include <stdio.h>
int cnt, c[10], l[20], r[20];
void q(int row,int n)
{
	if(row == n){cnt++; return;}
	int i;
	for(i=0;i<n;i++)
		if(c[i] == 0 && r[row-i+9] == 0 && l[row+i] == 0)
		{
			c[i] = 1, r[row-i+9] = 1, l[row+i] = 1;
			q(row+1,n);
			c[i] = 0, r[row-i+9] = 0, l[row+i] = 0;
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	q(0,n);
	printf("%d",cnt);
	return 0;
}
