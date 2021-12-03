/*   <<快速次方法>> 
int pow(ll x,ll y){
	if(y==0)
		return 1;
	ll z;
	z=pow(x,y/2);
	if(y%2==0)
		return z*z;
	else
		return z*z*x;
}
*/
/*
#include <stdio.h>
#define ll unsigned long long int
ll pow(ll,ll,int);
int main(){
	ll x,y;
	int m;
	scanf("%llu%llu%d",&x,&y,&m);
	printf("%llu\n",pow(x,y,m)%m);  //這裡還需%m一次 因為不用的話 1 0 1  會印出1 
									//因為pow直接return 1但沒%m 所以會錯 
	return 0;
}
ll pow(ll x,ll y,int m){
	if(y==0)
		return 1;
	ll z;
	z=pow(x,y/2,m);
	if(y%2==0)
		return (z*z)%m;
	else
		return ( ((z*z)%m) * (x%m) )%m;
}
*/

// x ^ y % m
#include <stdio.h>
#define ll long long int
ll fpw(ll x,ll y,ll m)		//MOD好MOD滿 1也不例外 
{
	if(y == 0) return 1%m;
	ll a = fpw(x,y/2,m);
	if(y%2 == 1) return (((a%m) * (a%m))%m * (x%m))%m;
	else return ((a%m) * (a%m))%m;
}
int main()
{
	ll x, y ,m;
	scanf("%lld%lld%lld",&x,&y,&m);
	printf("%lld\n",fpw(x,y,m));
	return 0;
}
