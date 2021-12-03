/*#include<stdio.h>
#include<string.h>
int mystrncmp(char* substr,char* str,int l){
	int i;
	for(i=0;i<l;i++)
		if(substr[i]!=str[i])
			return 0;
	return 1;
}
int main(){
	char str[1001],substr[1001];
	int n,a,b,i,cnt=0;
	scanf("%s",str);
	scanf("%s",substr);
	scanf("%d",&n);
	while(n){
		scanf("%d%d",&a,&b);
		for(i=a-1;i<=(b-strlen(substr));i++)
			if(mystrncmp(substr,str+i,strlen(substr)))
				cnt++;
		printf("%d\n",cnt);
		cnt=0;
		n--;
	}
	return 0;
}*/
/*#include<stdio.h>
#include<string.h>
int mystrncmp(char* substr,char* str,int l){
	int i;
	for(i=0;i<l;i++)
		if(substr[i]!=str[i])
			return 0;
	return 1;
}
int main(){
	int map[1000]={0};
	char str[1001],substr[1001];
	int n,a,b,i,cnt=0;
	scanf("%s",str);
	scanf("%s",substr);
	scanf("%d",&n);
	for(i=0;i<=(strlen(str)-strlen(substr));i++)
		if(mystrncmp(substr,str+i,strlen(substr)))
			map[i]++;
	while(n){
		scanf("%d%d",&a,&b);
		for(i=a-1;i<=(b-strlen(substr));i++){
			if(map[i])
				cnt++;
		}
		printf("%d\n",cnt);
		cnt=0;
		n--;
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
int main(){
	int map[1001]={0};
	char str[1001],substr[1001];
	int n,a,b,i,layg=0;
	scanf("%s",str);
	scanf("%s",substr);
	scanf("%d",&n);
	for(i=0;i<=(strlen(str)-strlen(substr));i++){
		if(strncmp(substr,str+i,strlen(substr))==0)
			layg++;
		map[i+1]=layg;
	}
	while(n){
		scanf("%d%d",&a,&b);
		printf("%d\n",map[b-strlen(substr)+1]-map[a-1]);
		n--;
	}
	return 0;
}







/*
#include <stdio.h>
#include <string.h>
char str[1005];
char sub[1005];
int same[1005];
int main(){
	int t,l,r,i,a;
	scanf("%s",str);
	scanf("%s",sub);
	scanf("%d",&t);
	a=strlen(sub);
	for(i=0;i<=strlen(str)-a;i++){
		same[i+1]=same[i];
		if(strncmp(str+i,sub,a)==0){
			same[i+1]++;
		}
	}
	while(t){
		scanf("%d%d",&l,&r);
		printf("%d\n",same[r-a+1]-same[l-1]);
		t--;
	} 
	return 0;
}
*/
