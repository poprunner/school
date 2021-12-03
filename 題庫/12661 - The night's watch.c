/*#include <stdio.h>
int a[5005];
int max;
void chs(int head,int tail,int m,int k){
	int i,min;
	if(k>0){
		if(k>=m-1){									//若控制者>本人順序直接挑選出能拿到max的方法 
			for(i=0;i<=m-1;i++){					//!! m要減1 k不用 因為k可用完 m於1時就輪到本人 !! 
				if( a[head+i] > a[tail-(m-1)+i] ){
					if(a[head+i]>max){
						max=a[head+i];
					}
				}else{								
					if(a[tail-(m-1)+i]>max){
						max=a[tail-(m-1)+i];
					}
				}	
			}
		}else{
			for(i=0;i<=k;i++){
				chs(head+i,tail-k+i,m-k,0);			//若控制者<本人順序先將控制者的所有方法都放完 
			}
		}	
	}else{
		if( a[head] > a[tail-(m-1)] ){				//放完後開始讓別人隨機選 輪到自己選當然選大的 
			min=a[head];
		}else{
			min=a[tail-(m-1)];
		}
		for(i=0;i<=m-1;i++){						//若挑的<最小值 更新min 
			if( a[head+i] > a[tail-(m-1)+i] ){		//挑可挑兩者中較大的 
				if(a[head+i]<min){
					min=a[head+i];
				}
			}else{
				if(a[tail-(m-1)+i]<min){
					min=a[tail-(m-1)+i];
				}
			}
		}
		if(min>max){								//若此次最小值>max 更新max 因為奇方法可以找出眾 
			max=min;								//min值中的最大值 
		}
	}
}
int main(){
	int t,n,m,k,i;
	scanf("%d",&t);
	while(t){
		scanf("%d%d%d",&n,&m,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		chs(0,n-1,m,k);
		printf("%d\n",max);
		max=0;
		t--;
	} 
	return 0;
}*/




/*
#include <stdio.h>
int seq[5005];
int max;
void pick(int f,int l,int m,int k){
	int i,j,min;
	if(k>=m-1){
		for(i=0;i<m;i++){
			if(seq[f+i]>seq[l-(m-1)+i]){
				if(seq[f+i]>max){ 
					max=seq[f+i];
				} 
			}else{
				if(seq[l-(m-1)+i]>max){ 
					max=seq[l-(m-1)+i];
				}
			}
		}
	}else{
		for(i=0;i<=k;i++){
			if(seq[f+i]>seq[l-k+i-(m-k-1)]){
				min=seq[f+i];
			}else{					
				min=seq[l-k+i-(m-k-1)];
			}
			for(j=1;j<m-k;j++){
				if(seq[f+i+j]>seq[l-k+i-(m-k-1)+j]){
					if(seq[f+i+j]<min){ 
						min=seq[f+i+j];
					}
				}else{
					if(seq[l-k+i-(m-k-1)+j]<min){ 
						min=seq[l-k+i-(m-k-1)+j];
					}
				}
			}
			if(min>max){
				max=min;
			}
		}
	}
}
int main(){
	int t,n,m,k,i;
	scanf("%d",&t);
	while(t){
		scanf("%d%d%d",&n,&m,&k);
		for(i=0;i<n;i++){
			scanf("%d",&seq[i]);
		}
		pick(0,n-1,m,k);
		printf("%d\n",max);
		max=0;
		t--;
	}
	return 0;
}
*/




#include <stdio.h>
int a[5010];
int main()
{
	int t, n, m, k,    l, r, ll, rr,    chs, min = (int)1e9+10, max = 0;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(l=0;l<n;l++)
			scanf("%d",&a[l]);
		if(k >= m-1)
			for(l=0,r=n-1-m+1;r<n;l++,r++)
			{
				if(a[l] > a[r]) chs = a[l];
				else chs = a[r];
				if(chs > max) max = chs;
			}
		else
			for(l=0,r=n-1-k;r<n;l++,r++)
			{
				for(ll=l,rr=r-(m-k)+1;rr<=r;ll++,rr++)
				{
					if(a[ll] > a[rr]) chs = a[ll];
					else chs = a[rr];
					if(chs < min) min = chs;
				}
				if(min > max) max = min;
				min = (int)1e9+10;
			}
		printf("%d\n",max);
		
		max = 0;
		t--;
	}
	return 0;
}


 
