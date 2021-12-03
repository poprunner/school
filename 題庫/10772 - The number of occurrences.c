/*#include<stdio.h>
#include<string.h>
int main(void){
	char str[5],c[9][9];
	int n,i,j,cnt=0,max=0;
	scanf("%s",str);
	scanf("%d",&n);	
	for(i=0;i<n;i++)
		scanf("%s",c[i]);
	for(i=0;i<n;i++){
		for(j=0;( strlen(c[i])-strlen(str) ) >= j;j++){
			if(strncmp( str,c[i]+j,strlen(str) ) == 0 ){//c[i]+j表示開頭位置往後移 
				cnt++;
			}
		}
		if(cnt>max)
			max=cnt;
		cnt=0;
	}
	printf("%d",max);
	return 0;
}*/




#include <stdio.h>
#include <string.h>
int main()
{
	char a[5], b[10];							//用迴圈能使 b 不用開二維陣列比較方便 
	int n, i, j, cnt = 0, max = 0, len;
	scanf("%s%d",a,&n);
	len = strlen(a);
	for(i=0;i<n;i++)
	{
		scanf("%s",b);							//一次讀一行來比較 
		for(j=0;j<=strlen(b)-len;j++)			//j <= strlen(b) - strlen(a)
			if(strncmp(a,b+j,len) == 0) cnt++;	//用 strncmp 比較方便不用擔心其他問題 
		if(cnt > max) max = cnt;
		cnt = 0;
	}
	printf("%d",max);
	return 0;
}
