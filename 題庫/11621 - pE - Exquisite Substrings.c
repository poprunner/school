/*	TLE
#include <stdio.h>
#include <string.h>
int main(){
	int s=0,i,j,k,l;
	char str[2001];
	while(scanf("%s",str)!=EOF){
		for(l=0;l<=strlen(str)-2;l++){
			for(i=2;l+i-1<strlen(str);i++){
				for(j=l,k=l+i-1;k>j;j++,k--){
					if(str[j]!=str[k]){
						break;
					}else if(k-j<=2){
						s++;
					}
				}
			}
		}
		printf("%d\n",s);
		s=0;
	}
	return 0;
}
*/


/*
#include <stdio.h>		//此題邊界值極為重要 
#include <string.h>
int main(){
	int s=0,i,j;
	char str[2001],restr[2001];
	while(scanf("%s",str)!=EOF){
		for(i=0;i<strlen(str);i++){
			restr[strlen(str)-1-i]=str[i];
		}
		restr[strlen(str)]='\0';			//做一個到序陣列 
		for(i=0;i<strlen(str)-1;i++){		//起頭位置 
			for(j=2;i+j-1<strlen(str);j++){	//比幾個字母 
				if(strncmp(str+i,restr+strlen(str)-1-(i+j-1),j/2)==0){//比較 
					s++;
				}
			}
		}
		printf("%d\n",s);					//印出 
		s=0;
	}
	return 0;
}
*/



/*
#include <stdio.h>
#include <string.h>
char str[2010], rev[2010];
int main()
{
	int i, j, l, cnt = 0;
	while(scanf("%s",str)!=EOF)
	{
		l = strlen(str);
		for(i=0;i<l;i++)
			rev[l-1-i] = str[i];
		for(i=2;i<=l;i++)
			for(j=0;j+i-1<l;j++)
				if(!strncmp(str+j,rev+(l-1)-(j+i-1),i/2)) cnt++;
		printf("%d\n",cnt);
		
		cnt = 0;
	}
	return 0;
}
*/



#include <stdio.h>
#include <string.h>
char str[2010];
int cnt;
void eq(int l)
{
	int i, j, k;
	for(i=0;i<l;i++)
	{
		for(j=i-1,k=i+1;j>=0&&k<l;j--,k++)
			if(str[j] == str[k]) cnt++;
			else break;
		for(j=i,k=i+1;j>=0&&k<l;j--,k++)
			if(str[j] == str[k]) cnt++;
			else break;
	}
}
int main()
{
	while(scanf("%s",str)!=EOF)
	{
		eq(strlen(str));
		printf("%d\n",cnt);
		
		cnt = 0;
	}
	return 0;
}
