//從P(0)開始因為P(0)=-1 所以最後答案可能會變負 所以要 !多加一個MOD!

//也可從P(1)開始 此時最後乘上係數 13 12 1 且矩陣只要取 n-1 次方 因為從P(1)開始
//此時因為係數都正便不需再多加MOD
/*
#include <stdio.h>              //P(i) = P(i-1) + 2*P(i-2) + P(i-3)
#define ll long long int        //P(1)=1, P(2)=12, P(3)=13 -> P(0)=-1
#define MOD (int)(1e9+7)        // |   |   |1 2 1|n |12|
typedef struct{                 // |   | = |1 0 0|  | 1|
    ll a[9];                    // |ans|   |0 1 0|  |-1|
}_A;                            //ans = 12*a[6] + 1*a[7] + (-1)*a[8]
_A multply(_A A,_A B)
{
    _A C;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            C.a[3*i+j] = (
            (A.a[0+3*i]*B.a[0+j])%MOD + 
            (A.a[1+3*i]*B.a[3+j])%MOD + 
            (A.a[2+3*i]*B.a[6+j])%MOD  ) % MOD;
    return C;
}
_A fpw(int n)
{
    _A A, G;
    A.a[0]=1,A.a[1]=2,A.a[2]=1,
    A.a[3]=1,A.a[4]=0,A.a[5]=0,
    A.a[6]=0,A.a[7]=1,A.a[8]=0;
    if(n == 0) return A;
    G = fpw(n-1);
    return multply(G,G);
}
int main()
{
    int t;
    ll x;
    _A ANS;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&x);
        for(int i=0;i<9;i++)
            if(i%4 == 0) ANS.a[i] = 1;
            else ANS.a[i] = 0;
        for(int i=0;i<64;i++)
            if((x >> i)%2)
                ANS = multply(fpw(i),ANS);                         //多加一個MOD
        printf("%lld\n",((ANS.a[6]*12)%MOD+ANS.a[7]%MOD-ANS.a[8]%MOD+MOD) % MOD);
    }
    return 0;
}
*/



#include <stdio.h>
#include <string.h>
#define ll long long int
#define MOD (ll)(1e9+7)
#define dim 3
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
    F.a[0][0] = 1, F.a[0][1] = 2, F.a[0][2] = 1;
    F.a[1][0] = 1, F.a[1][1] = 0, F.a[1][2] = 0;
    F.a[2][0] = 0, F.a[2][1] = 1, F.a[2][2] = 0;
    //
    if(n == 0) return I;
    M = fpw(n/2);
    if(n%2 == 1) return mul(mul(M,M),F);
    else return mul(M,M);
}
int main()
{
    ll n, ans, t;
    MAT ANS;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ANS = fpw(n-1);
        //  手動輸入要乘的向量
        ans = 13 * ANS.a[2][0] + 12 * ANS.a[2][1] + 1 * ANS.a[2][2];
        //
        printf("%lld\n",ans%MOD);
    }
    return 0;
}
