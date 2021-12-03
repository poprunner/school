/*#include "function.h"
 
int BS(int *a, int q, int n)
{
	if(n%2==0){
		if(a[n/2]>q){
			return BS(a,q,n/2);
		}else if(a[n/2]<q){
			return n/2+1+BS(a+n/2+1,q,n/2-1);
		}else{
			return n/2;
		}
	}else{
		if(a[n/2]>q){
			return BS(a,q,n/2);
		}else if(a[n/2]<q){
			return n/2+1+BS(a+n/2+1,q,n/2);
		}else{
			return n/2;
		}
	}
}
*/

#include "function.h"

int bi(int *a,int q,int l,int r)
{
	int m = l + (r-l)/2;	
	if(a[m] > q) bi(a,q,l,m-1);
	else if(a[m] < q) bi(a,q,m+1,r);
	else return m;
}
int BS(int *a,int q,int n)
{
	return bi(a,q,0,n-1);
} 
