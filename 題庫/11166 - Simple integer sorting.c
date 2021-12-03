/*#include <stdio.h>
#include <stdlib.h>
int a[10005];					//數列存放陣列 
int cmp(const void*,const void*);
int main(){
	int n,k,i;
	scanf("%d",&n);				//n組測資 
	while(n){					//做n次排序 
		scanf("%d",&k);			//待排數字數量 
		for(i=0;i<k;i++){		//輸入數列 
			scanf("%d",&a[i]);
		}
		qsort(a,k,sizeof(int),cmp);//快速排序 
		for(i=0;i<k;i++){		//印出來 
			printf("%d%c",a[i]," \n"[i==k-1]);
		}
		n--;
	}
	return 0;
}
int cmp(const void*_a,const void*_b){
	int a=*(int*)_a;
	int b=*(int*)_b;
	return a>b;
}*/

/*
#include <stdio.h>
int a[10005];					//數列存放陣列 
int main(){
	int n,k,i,j,tmp;
	scanf("%d",&n);				//n組測資 
	while(n){					//做n次排序 
		scanf("%d",&k);			//待排數字數量 
		for(i=0;i<k;i++){		//輸入數列 
			scanf("%d",&a[i]);
		}
		for(i=0;i<k-1;i++){		//泡沫排序 
			for(j=0;j<k-1-i;j++){
				if(a[j]>a[j+1]){
					tmp=a[j+1];
					a[j+1]=a[j];
					a[j]=tmp;
				}
			}
		}
		for(i=0;i<k;i++){		//印出來 
			printf("%d%c",a[i]," \n"[i==k-1]);
		}
		n--;
	}
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
double a[10005];					//數列存放陣列 
int cmp(const void*,const void*);
int main(){
	int n,k,i;
	scanf("%d",&n);				//n組測資 
	while(n){					//做n次排序 
		scanf("%d",&k);			//待排數字數量 
		for(i=0;i<k;i++){		//輸入數列 
			scanf("%lf",&a[i]);
		}
		qsort(a,k,sizeof(double),cmp);//快速排序 
		for(i=0;i<k;i++){		//印出來 
			printf("%f%c",a[i]," \n"[i==k-1]);
		}
		n--;
	}
	return 0;
}
int cmp(const void*_a,const void*_b){
	double a=*(double*)_a;
	double b=*(double*)_b;
	return a>b;
}
*/





#include <stdio.h>
int a[10010];
int cmp(const void *_a,const void *_b)
{
	int a = *(int*)_a;
	int b = *(int*)_b;
	return a > b;
}
int main()
{
	int t, n, i;
	scanf("%d",&t);
	while(t)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmp);
		for(i=0;i<n;i++)
			printf("%d%c",a[i]," \n"[i == n-1]);
		
		t--;
	}
	return 0;
}
