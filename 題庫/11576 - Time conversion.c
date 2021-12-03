/*#include<stdio.h>
int main(){
	char d1,d1t,d2,d3,d4,ap;//用char呈現
	int a=0;
	scanf("%c%c%c%c",&d1,&d2,&d3,&d4);
	d1t=d1;
	if( ( 10*(d1-'0') + (d2-'0') ) >= 12 ){
		a++;
		d1=( 10*(d1t-'0') + (d2-'0') - 12 ) / 10 + '0';//d1t必須要 不然d1會先被改掉 
		d2=( 10*(d1t-'0') + (d2-'0') - 12 ) % 10 + '0';//而造成此行出錯 
	}
	if(a){
		ap='p';
	}else{
		ap='a';
	}
	printf("%c%c:%c%c %c.m.",d1,d2,d3,d4,ap);
	a=0;
	return 0;
}*/ 




#include <stdio.h>
int main()
{
	int h, m;
	char ap[] = {"a.m."};			//先預設是a.m. 
	scanf("%2d%2d",&h,&m);			//一次讀進2個字 
	if(h >= 12)						//如果hour >= 12 改為下午 
	{
		h-=12;						//減12小時 
		ap[0] = 'p';				//第一個字改成p 
	}
	printf("%02d:%02d %s",h,m,ap);	//記得是 %02d 表佔兩格 前面補0 
	return 0;
}
