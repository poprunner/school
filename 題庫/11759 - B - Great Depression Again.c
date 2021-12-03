//核心思想 將x+y 切成兩段 分開排序 前面 a-b 由大排到小 後面 a 由大排到小
//則前段最前面 cut-y 個就是要翻成 x 的(因為最前面 a-b 最大 翻成 x 的收益比翻後面的大)
//之後都是 y 的 後段則都是 x 的
//然後從 y 處一直切到 x+y 處 選其中可得到最大值的切法即是答案

//最初完成版
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[25];
    int idx, a, b, dif;
}FAC;
int max, maxa, ansidx[500];
int cmpb(const void *_c,const void *_d)     //降序
{
    int c = ((FAC*)_c)->b;
    int d = ((FAC*)_d)->b;
    return d - c;
}
int cmpdif(const void *_c,const void *_d)   //降序
{
    int c = ((FAC*)_c)->dif;
    int d = ((FAC*)_d)->dif;
    return d - c;
}
int cmpa(const void *_c,const void *_d)     //降序
{
    int c = ((FAC*)_c)->a;
    int d = ((FAC*)_d)->a;
    return d - c;
}
int cmpidx(const void *_c,const void *_d)   //升序
{
    int c = ((FAC*)_c)->idx;
    int d = ((FAC*)_d)->idx;
    return c - d;
}
void check(int n,int cut,int x,int y,FAC* fac)
{
    int suma = 0, sumb = 0;
    qsort(fac,cut,sizeof(fac[0]),cmpdif);
    qsort(fac+cut,n-cut,sizeof(fac[0]),cmpa);
    for(int i=0;i<x+y;i++)
    {
        if(i < cut-y) suma += fac[i].a;//== fac[i].b + fac[i].dif
        else if(i < cut) sumb += fac[i].b;
        else suma += fac[i].a;
    }
    if(suma+sumb > max || (suma+sumb == max && suma > maxa))
    {
        max = suma+sumb, maxa = suma;
        for(int i=0,j=0;j<x;i++)
            if(i < cut-y || i >= cut)
            {
                ansidx[j] = fac[i].idx;
                j++;
            }
    }
}
int main()
{
    FAC fac[500];
    char ans[500][25];
    int n, x, y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",fac[i].s,&fac[i].a,&fac[i].b);
        fac[i].dif = fac[i].a - fac[i].b;
        fac[i].idx = i;
    }
    for(int cut=y;cut<=x+y;cut++)
    {
        qsort(fac,n,sizeof(fac[0]),cmpb);   //每次check完都要重新排好
        check(n,cut,x,y,fac);
    }
    qsort(fac,n,sizeof(fac[0]),cmpidx);     //先按照 idx 順序排好
    for(int i=0;i<x;i++) strcpy(ans[i],fac[ansidx[i]].s);
    qsort(ans,x,sizeof(ans[0]),(int (*) (const void*,const void*))strcmp);
    for(int i=0;i<x;i++) printf("%s\n",ans[i]);
    return 0;
}
*/



//優化行數版
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[25];
    int idx, a, b, dif;
}FAC;
int max, maxa, ansidx[500];
int cmpidx(const void *c,const void *d){return ((FAC*)c)->idx - ((FAC*)d)->idx;}
int cmpa  (const void *c,const void *d){return ((FAC*)d)->a   - ((FAC*)c)->a  ;}
int cmpb  (const void *c,const void *d){return ((FAC*)d)->b   - ((FAC*)c)->b  ;}
int cmpdif(const void *c,const void *d){return ((FAC*)d)->dif - ((FAC*)c)->dif;}
void check(int n,int cut,int x,int y,FAC* fac)
{
    int suma = 0, sumb = 0;
    qsort(fac,cut,sizeof(fac[0]),cmpdif);
    qsort(fac+cut,n-cut,sizeof(fac[0]),cmpa);
    for(int i=0;i<x+y;i++)
    {
        if(i < cut-y) suma += fac[i].a;
        else if(i < cut) sumb += fac[i].b;
        else suma += fac[i].a;
    }
    if(suma+sumb > max || (suma+sumb == max && suma > maxa))
    {
        max = suma+sumb, maxa = suma;
        for(int i=0,j=0;j<x;i++)
            if(i < cut-y || i >= cut){ansidx[j] = fac[i].idx; j++;}
    }
}
int main()
{
    FAC fac[500];
    char ans[500][25];
    int n, x, y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",fac[i].s,&fac[i].a,&fac[i].b);
        fac[i].dif = fac[i].a - fac[i].b;
        fac[i].idx = i;
    }
    for(int cut=y;cut<=x+y;cut++)
    {
        qsort(fac,n,sizeof(fac[0]),cmpb);
        check(n,cut,x,y,fac);
    }
    qsort(fac,n,sizeof(fac[0]),cmpidx);
    for(int i=0;i<x;i++) strcpy(ans[i],fac[ansidx[i]].s);
    qsort(ans,x,sizeof(ans[0]),(int (*) (const void*,const void*))strcmp);
    for(int i=0;i<x;i++) printf("%s\n",ans[i]);
    return 0;
}
*/





//照a排序版
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[25];
    int idx, a, b, dif;
}FAC;
int max, maxa, ansidx[500];
int cmpidx(const void *c,const void *d){return ((FAC*)c)->idx - ((FAC*)d)->idx;}
int cmpa  (const void *c,const void *d){return ((FAC*)d)->a   - ((FAC*)c)->a  ;}
int cmpb  (const void *c,const void *d){return ((FAC*)d)->b   - ((FAC*)c)->b  ;}
int cmpdif(const void *c,const void *d){return ((FAC*)d)->dif - ((FAC*)c)->dif;}
void check(int n,int cut,int x,int y,FAC* fac)
{
    int suma = 0, sumb = 0;
    qsort(fac,cut,sizeof(fac[0]),cmpdif);
    qsort(fac+cut,n-cut,sizeof(fac[0]),cmpb);
    for(int i=0;i<x+y;i++)
    {
        if(i < cut-x) sumb += fac[i].b;
        else if(i < cut) suma += fac[i].a;
        else sumb += fac[i].b;
    }
    if(suma+sumb > max || (suma+sumb == max && suma > maxa))
    {
        max = suma+sumb, maxa = suma;
        for(int i=0,j=0;j<x;i++)
            if(i >= cut-x && i < cut){ansidx[j] = fac[i].idx; j++;}
    }
}
int main()
{
    FAC fac[500];
    char ans[500][25];
    int n, x, y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",fac[i].s,&fac[i].a,&fac[i].b);
        fac[i].dif = fac[i].b - fac[i].a;
        fac[i].idx = i;
    }
    for(int cut=x;cut<=x+y;cut++)
    {
        qsort(fac,n,sizeof(fac[0]),cmpa);
        check(n,cut,x,y,fac);
    }
    qsort(fac,n,sizeof(fac[0]),cmpidx);
    for(int i=0;i<x;i++) strcpy(ans[i],fac[ansidx[i]].s);
    qsort(ans,x,sizeof(ans[0]),(int (*) (const void*,const void*))strcmp);
    for(int i=0;i<x;i++) printf("%s\n",ans[i]);
    return 0;
}







//TLE 但正確
//使用二叉法 O(2^n) 無敵耗時間
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[25];
    int idx, a, b, ranka, rankb;
}data;
data fac[500];
int n, x, y, ranka[500], rankb[500];
int min_minus = (int)1e9, mindel[500], deletea[500], deleteb[500];
int cmpa(const void *_a,const void *_b)
{
    int c = ((data*)_a)->a;
    int d = ((data*)_b)->a;
    return d - c;
}
int cmpb(const void *_a,const void *_b)
{
    int c = ((data*)_a)->b;
    int d = ((data*)_b)->b;
    return d - c;
}
int cmpidx(const void *_a,const void *_b)
{
    int c = ((data*)_a)->idx;
    int d = ((data*)_b)->idx;
    return c - d;
}
void check(int mx,int my,int minus)
{
    if(minus > min_minus) return;
    for(int i=0;i<mx;i++)
        if(fac[ranka[i]].rankb < my && 
        deleteb[fac[ranka[i]].rankb] == 0 && deletea[i] == 0)
        {
            deleteb[fac[ranka[i]].rankb] = 1;
            check(mx,my+1,minus+(fac[ranka[i]].b-fac[rankb[my]].b));
            deleteb[fac[ranka[i]].rankb] = 0;
            deletea[i] = 1;
            check(mx+1,my,minus+(fac[ranka[i]].a-fac[ranka[mx]].a));
            deletea[i] = 0;
            return;
        }
    if(minus < min_minus)    //沒重複 -> 結算
    {
        min_minus = minus;
        for(int i=0;i<x;i++) mindel[i] = deletea[i];
    }
}
int main()
{
    char ans[500][25];
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",fac[i].s,&fac[i].a,&fac[i].b);
        fac[i].idx = i;
    }
    qsort(fac,n,sizeof(data),cmpa);
    for(int i=0;i<n;i++){fac[i].ranka = i; ranka[i] = fac[i].idx;}
    qsort(fac,n,sizeof(data),cmpb);
    for(int i=0;i<n;i++){fac[i].rankb = i; rankb[i] = fac[i].idx;}
    qsort(fac,n,sizeof(data),cmpidx);
    check(x,y,0);
    int j = 0, has = 0;
    while(has < x)
    {
        if(mindel[j] == 0)
        {
            strcpy(ans[has],fac[ranka[j]].s);
            has++;
        }
        j++;
    }
    qsort(ans,x,sizeof(ans[0]),(int (*) (const void*,const void*))strcmp);
    for(int i=0;i<x;i++) printf("%s\n",ans[i]);
    return 0;
}
*/
