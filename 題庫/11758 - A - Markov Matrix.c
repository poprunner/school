#include <stdio.h>
typedef struct{
    double a[25];
}_MAT;
_MAT mul(_MAT A,_MAT B)
{
    _MAT C;
    for(int i=0;i<25;i++) C.a[i] = 0;
    for(int i=0;i<25;i++)
        for(int j=0;j<5;j++)
            C.a[i] += A.a[i/5*5+j]*B.a[j*5+i%5];
    return C;           //列 *5+行     列*5+行
}
int main()
{
    int t, n, ans;
    double p;
    _MAT A, X;
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        for(int i=0;i<25;i++){A.a[i] = 0, X.a[i] = 0;}

        scanf("%d",&n);
        for(int i=0;i<25;i++) if(i%5 < n && i/5 <n) scanf("%lf",&A.a[i]);
        for(int i=0;i<25;i+=5) if(i/5 < n) scanf("%lf",&X.a[i]);
        scanf("%lf",&p);
        while(X.a[0] > p && ans < 100)
        {
            X = mul(A,X);
            ans++;
        }
        if(ans == 100) printf("Never\n");
        else printf("%d\n",ans);
        /*
        for(int i=0;i<25;i++)
            if(i%5 < n && i/5 <n)
                printf("%f%c",X.a[i]," \n"[i%5 == n-1]);
        */
    }
    return 0;
}
