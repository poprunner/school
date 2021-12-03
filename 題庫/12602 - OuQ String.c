#include <stdio.h>
int hasprint,open;
long long int power(int k){
	long long int z=1;
	int i;
	for(i=0;i<k;i++){
		z*=2;
	}
	return z;
}
void findprin(long long int l,int k,long long int total,int len){
	if( k == 0 ){
		return;
	}
	if( l == 0 || open ){
		open++;
		if(hasprint==len){
			return;
		}
		printf("O");
		hasprint++;
		if(hasprint==len){
			return;
		}
	}
	if( l  < total/2 || open ){
		findprin(l-1,k-1,(total-3)/2,len);
	}
	if( l == total/2 || open ){	
		open++;	
		if(hasprint==len){
			return;
		}
		printf("u");
		hasprint++;			
		if(hasprint==len){
			return;
		}	
	}
	if( l  < total-1 || open ){
		findprin(l-total/2-1,k-1,(total-3)/2,len);		
	}
	if( l == total-1 || open ){	
		open++;	
		if(hasprint==len){
			return;
		}
		printf("Q");		
		hasprint++;			
		if(hasprint==len){
			return;
		}	
	}
}
int main(){
	//
	int k;
	long long int l,r;
	int len;
	long long int total;
	while(scanf("%d%lld%lld",&k,&l,&r)!=EOF){
		len=r-l+1;
		total=3*(power(k)-1);
		//找開頭順便印 
		findprin(l,k,total,len);
		printf("\n");
		hasprint=0;
		open=0;
	}
	return 0;
}
