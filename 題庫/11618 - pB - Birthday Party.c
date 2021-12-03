/*#include <stdio.h>		//一數之倍數之餘在某域中所佔個數為其與域值之公因數 
long long int gcd(long long int x,long long int y){	//最大公因數 
	if(x%y==0){
		return y;
	}else{
		return gcd(y,x%y);
	}
}
long long int lcm(long long int x,long long int y,long long int z){//最小公倍數 
	return (x/gcd(x,y)*y)/gcd(x/gcd(x,y)*y,z)*z;
}
int main(){
	int t;
	long long int n,x,y,z;
	scanf("%d",&t);
	while(t){
		scanf("%lld%lld%lld%lld",&n,&x,&y,&z);	//輸入 
		x=gcd(n,x);								//取其公因數 
		y=gcd(n,y);
		z=gcd(n,z);
		printf("%lld\n",n/lcm(x,y,z));			//全部除其公倍數 
		t--;
	}
	return 0;
}*/




#include <stdio.h>
#define ll long long int
ll gcd(ll a,ll b)
{
	if(b == 0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b,ll c)
{
	ll ab = a/gcd(a,b)*b;
	return ab/gcd(ab,c)*c;
}
int main()
{
	int t;
	ll n, a, b, c;
	scanf("%d",&t);
	while(t)
	{
		scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
		a = gcd(n,a);
		b = gcd(n,b);
		c = gcd(n,c);
		printf("%lld\n",n/lcm(a,b,c));
		t--;
	}
	return 0;
} 
