/*#include <stdio.h>
#define ll long long int
#define MOD (int)(1e9+7)
typedef struct{
    ll a, b, c, d;
}_A;
_A pow2(_A A,int x)
{
    if(x == 0) return A;
    ll e = A.a, f = A.b, g = A.c, h = A.d;
    A.a = ((e*e)%MOD+(f*g)%MOD)%MOD;
    A.b = ((e*f)%MOD+(f*h)%MOD)%MOD;
    A.c = ((e*g)%MOD+(g*h)%MOD)%MOD;
    A.d = ((f*g)%MOD+(h*h)%MOD)%MOD;
    return pow2(A,x-1);
}
int main()
{
    ll n, e, f, g, h;
    _A A, O, F;
    O.a=1,O.b=1,O.c=1,O.d=0;
    while(scanf("%lld",&n) != EOF)
    {
        F.a=1,F.b=0,F.c=0,F.d=1;
        for(int i=0;i<64;i++)
            if((n >> i)%2)
            {
                A = pow2(O,i);
                e = F.a, f = F.b, g = F.c, h = F.d;
                F.a = ((A.a*e)%MOD+(A.b*g)%MOD)%MOD;
                F.b = ((A.a*f)%MOD+(A.b*h)%MOD)%MOD;
                F.c = ((A.c*e)%MOD+(A.d*g)%MOD)%MOD;
                F.d = ((A.c*f)%MOD+(A.d*h)%MOD)%MOD;
            }
        printf("%lld\n",F.c);
    }
    return 0;
}*/











/*
#include <stdio.h>
#define ll long long int
#define MOD (int)(1e9+7)
typedef struct{
    ll a, b, c, d;
}_A;
_A mltply(_A A,_A B)                        //矩陣相乘
{
    _A C;
    C.a = ((A.a*B.a)%MOD+(A.b*B.c)%MOD)%MOD;//取MOD時機不影響運算結果 因此全取
    C.b = ((A.a*B.b)%MOD+(A.b*B.d)%MOD)%MOD;
    C.c = ((A.c*B.a)%MOD+(A.d*B.c)%MOD)%MOD;
    C.d = ((A.c*B.b)%MOD+(A.d*B.d)%MOD)%MOD;
    return C;
}
_A pow2(int i)                              //A矩陣的2的i次方
{
    _A G, A;
    A.a=1,A.b=1,A.c=1,A.d=0;                //費式數列矩陣
    if(i == 0) return A;
    G = pow2(i-1);
    return mltply(G,G);
}
int main()
{
    ll n;
    _A F;
    while(scanf("%lld",&n) != EOF)
    {
        F.a=1,F.b=0,F.c=0,F.d=1;            //初始為I矩陣
        for(int i=0;i<64;i++)               //LL 64位元看成二進位
            if((n >> i)%2)                  //若該位數為1 表示有該2的i次方費式矩陣要乘
                F = mltply(pow2(i),F);      //答案矩陣乘上該2的i次方矩陣
        printf("%lld\n",F.c);               //答案矩陣的c元素即為答案
    }
    return 0;
}
*/


#include <stdio.h>
#include <string.h>
#define ll long long int
#define MOD (ll)(1e9+7)
#define dim 2
typedef struct{
    ll a[dim][dim];
}MAT;
MAT mul(MAT A,MAT B)
{
    MAT C;
    memset(&C,0,sizeof(C));
    for(int i=0;i<dim;i++) for(int j=0;j<dim;j++) for(int k=0;k<dim;k++)
        C.a[i][k] += ((A.a[i][j] % MOD) * (B.a[j][k] % MOD)) % MOD;
    for(int i=0;i<dim;i++) for(int j=0;j<dim;j++) C.a[i][j] %= MOD;
    return C;
}
MAT fpw(ll n)
{
    MAT I, F, M;
    memset(&I,0,sizeof(I));
    for(int i=0;i<dim;i++) I.a[i][i] = 1;
    //  手動輸入要乘的矩陣
    F.a[0][0] = 1, F.a[0][1] = 1;
    F.a[1][0] = 1, F.a[1][1] = 0;
    //
    if(n == 0) return I;
    M = fpw(n/2);
    if(n%2 == 1) return mul(mul(M,M),F);
    else return mul(M,M);
}
int main()
{
    ll n, ans;
    MAT ANS;
    while(scanf("%lld",&n) != EOF)
    {
        ANS = fpw(n);
        //  手動輸入要乘的向量
        ans = 1 * ANS.a[1][0] + 0 * ANS.a[1][1];
        //
        printf("%lld\n",ans%MOD);
    }
    return 0;
}
