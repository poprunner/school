//使用單向搜尋法會爆(TLE) 
/*#include <stdio.h>
int a[200005];
int b[200005];
int p[200006];
int main(){
	int n,i,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]); 
	}
	for(i=0;i<n;i++){
		p[a[i]]=i+1;
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]); 
	}
	for(i=0;i<n;i++){
		if(p[b[i]]>flag){			
			a[i]=p[b[i]]-flag;	//絕對不能用b[i]  否則此行改值後 
			flag=p[b[i]];		//此行的p[b[i]]值就會變				
		}else{
			a[i]=0;  
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);
	return 0;
}*/
//修正版 
/*#include <stdio.h>
int a[200005];
int seq[200005];
int b[200005];
int eat[200005];
int main(){
	int n,i;
	int ate=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		seq[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		if(seq[b[i]]<=ate){
			eat[i]=0;
		}else{
			eat[i]=seq[b[i]]-ate;
			ate=seq[b[i]];
		}
	}
	for(i=1;i<=n-1;i++){
		printf("%d ",eat[i]);
	}
	printf("%d\n",eat[n]);
	return 0;
}*/ 



/*
#include <stdio.h>
int a[200005];
int eaten[200005];
int main(){
	int n,b,flag=0,eat,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){		
		eat=0;
		scanf("%d",&b);		
		if(!eaten[b])
			for(j=flag+1;j<=n;j++){	
				eaten[a[j]]=1;	
				if(a[j]==b){
					eat=j-flag;
					flag=j;
					break;
				}
			}
		printf("%d%c",eat," \n"[i==n]);
	}
	return 0;
}
*/




#include <stdio.h>
int seq[(int)2e5+10];
int main()
{
	int n, i, w, req, eaten = 0, eat;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		seq[w] = i;
	}
	while(n)
	{
		scanf("%d",&req);
		if(eaten > seq[req]) eat = 0;
		else
		{
			eat = seq[req] - eaten;
			eaten = seq[req];
		}
		printf("%d%c",eat," \n"[n == 1]);
		n--;
	}
	return 0;
}
