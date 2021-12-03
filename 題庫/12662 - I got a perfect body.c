/*
#include <stdio.h>
#include <stdlib.h>
int a[(int)3e5+100];
int cmp(const void *_c,const void *_b)
{
    int c = *(int*)_c;
    int b = *(int*)_b;
    return c >= b;
}
int main()
{
    int t, n, p, k, cnt, max;
    long long int testp, sum;
    scanf("%d",&t);
    while(t--)
    {
        max = 0, sum = 0;
        scanf("%d%d%d",&n,&p,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        qsort(a+1,n,sizeof(a[0]),cmp);
        for(int r=0;r<k;r++)
        {
            testp = p, cnt = 0;
            sum += a[r];
            if(testp-sum >= 0)
            {
                testp -= sum;
                cnt = r;
                for(int i=r+k;i<=n;i+=k)//一直錯的原因: 把此段放在外面 萬一 testp-sum < 0
                    if(testp-a[i] >= 0) //則 testp -= sum; 不會執行 造成答案錯誤
                    {                   //錯誤例子: 10 4 4
                        testp -= a[i];  //1 2 3 4 4 4 4 4 4 4
                        cnt = i;        //得出結果:7  正確答案:4
                    }                   //因為 1 2 3 的sum 6 因為 > 4 而沒減掉
            }                           //導致直接減掉 第七個4 (4-4 = 0) 導致出來答案為7  
            if(cnt > max) max = cnt;    //若要分開則不應該用前綴和 要一個一個扣 但這樣會TLE
        }
        printf("%d\n",max);
    }
    return 0;
}
*/



#include <stdio.h>
#include <stdlib.h>
#define ll long long int
ll a[(int)3e5+100];
int cmp(const void *_x,const void *_y)
{
    ll x = *(ll*)_x;
    ll y = *(ll*)_y;
    return x > y;
}
int main()
{
    int t, n, p, k, max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&p,&k);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        qsort(a+1,n,sizeof(a[0]),cmp);
        for(int i=1;i<=n;i++)
        {
            if(i-k >= 0) a[i] += a[i-k];    //過k 跳加
            else a[i] += a[i-1];            //未過k 累加
        }
        for(int i=0;i<=n;i++)
            if(a[i] <= p) max = i;          //不能中途break因為此函數並非遞增函數
        printf("%d\n",max);
    }
    return 0;
}
