/*#include <stdio.h>
#define ll long long int
int a[200000];
int y[200000];
char str[] = {"2\n0 4\n1\n0\n10\n0 1 2 3 4 5 6 7 8 9\n2\n0 1"};
int main()
{
    int n,k,d;
    while(scanf("%d%d",&n,&k) != EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&d);
            a[i] = d%k;
        }
        for(int i=0;i<n;i++)
            for(int j = 0;j<=n;j++)
           

    }
    printf("%s",str);
    return 0;
}*/


#include <stdio.h>
#define ll long long int
int a[200000];
int gcd(int a,int b)
{
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}
int main()
{
    int n,k,d;
    while(scanf("%d%d",&n,&k) != EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&d);
            d %= k;
            a[i] = gcd(d,k);
        }
        for(int i=0;i<n-1;i++)
            a[i+1] = gcd(a[i],a[i+1]);
        printf("%d\n",k/a[n-1]);
        for(int i=0;i<k;i++)
            if(i%a[n-1] == 0) printf("%d%c",i," \n"[k-a[n-1] == i]);
    }
    return 0;
}
