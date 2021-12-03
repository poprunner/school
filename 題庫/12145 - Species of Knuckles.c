/*#include <stdio.h>
char a[26];
int main(){
	int n,i,kk=0;
	char c;
	scanf("%d",&n);
	while(getchar()!='\n');		//吃字元時先把換行吃掉以免吃錯 
	
	if(n==1||n>26){				//如果只有1個字或大於26個字 則一定會 Knuckles 
		kk=1;					//(1個本身就是、大於26則一定會有重複的英文字母) 
		n=0;						
	}
	while(n){					//2~26使用陣列檢視 
		scanf("%c",&c);
		for(i=0;i<26;i++)
			if(c=='a'+i){ 
				a[i]++;
				if(a[i]>1){		//若該字母出現一次以上  則Knuckles  
					kk=1;
					n=1;		//break 只會break for n改1使while也停止 
					break;
				}
			}
		n--;
	}

	if(kk) printf("I'm the god of Knuckles!\n");
	else   printf("Different makes perfect\n");
	return 0;
}*/



/*
#include <stdio.h>
int a[26];
int main()
{
	int n, i, yes = 0;
	char c;
	scanf("%d",&n);
	while(getchar() != '\n');			//吃字元時先把換行吃掉以免吃錯
	for(i=0;i<n;i++)
	{
		scanf("%c",&c);
		a[c-'a']++;
		if(a[c-'a'] > 1){yes = 1; break;}
	}
	if(yes || n == 1) printf("I'm the god of Knuckles!\n");
	else printf("Different makes perfect\n");
	return 0;
}
*/

#include <stdio.h>
char a[26];
int main()
{
	int n, i, k = 0;
	char c;
	scanf("%d",&n);
	while(getchar() != '\n');	//切記吃字元前要先清乾淨換行 
	for(i=0;i<n;i++)
	{
		scanf("%c",&c);
		a[c-'a']++;
		if(a[c-'a'] > 1) k = 1; 
	}
	if(k || n == 1) printf("I'm the god of Knuckles!\n");
	else printf("Different makes perfect\n");
	return 0;
}
