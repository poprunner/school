#include <stdio.h>
int n, m, ans;   //n:queen   m:castle
int qup[20], ql[40], qr[40], cup[20], cl[40], cr[40];
void find(int q,int c,int r)
{
    if(r == n+m){ans++; return;}
    for(int j=0;j<n+m;j++)
    {
        if(q > 0 && !qup[j] && !ql[r-j+17] && !qr[r+j] &&
           !cup[j] && !cl[r-j+17] && !cr[r+j])
        {
            qup[j]++, ql[r-j+17]++, qr[r+j]++;
            find(q-1,c,r+1);
            qup[j]--, ql[r-j+17]--, qr[r+j]--;
        }
        if(c > 0 && !qup[j] && !ql[r-j+17] && !qr[r+j] && !cup[j])
        {
            cup[j]++, cl[r-j+17]++, cr[r+j]++;      
            //要用 ++ 不能用 =1 因為斜向能同時有兩個以上城堡 
            //直接歸0會同時消除掉另一個城堡 造成皇后忽略掉該城堡
            find(q,c-1,r+1);
            cup[j]--, cl[r-j+17]--, cr[r+j]--;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    find(n,m,0);
    printf("%d\n",ans);
    return 0;
}
