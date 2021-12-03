// contest == m(m-1)/2 + m(2^n-1)
// people == 2^n * m
// m為奇數 可表為2k+1 --> contest == (2k+1)(k-1) + people
// 用 contest == (2k+1)(k-1) + 2^n*(2k+1) 確認
// (2k+1)(k-1) + 2^n*(2k+1) 在k>1處遞增 k可2分法

#include <stdio.h>
#define ll long long int
ll bi(ll contest,ll pow_2,ll l,ll r)
{
    if(l == r)
        if(contest == (2*l+1)*(l-1) + pow_2*(2*l+1)) return l;
        else return -1;
    ll m = l + (r - l)/2;
    if(contest > (2*m+1)*(m-1) + pow_2*(2*m+1)) return bi(contest,pow_2,m+1,r);
    else return bi(contest,pow_2,l,m);
}
int main()
{
    int t;
    ll n, pow_2, k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=0;i<60;i++)
        {
            pow_2 = (ll)1 << i;
            k = bi(n,pow_2,0,(pow_2 > (ll)1e9) ? (ll)(1e18/pow_2) : (ll)1e9);
            if(k != -1) break;
        }
        if(k == -1) printf("%d\n",-1);
        else printf("%lld\n",pow_2*(2*k+1));
    }
    return 0;
}
