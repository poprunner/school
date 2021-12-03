#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int idx, adm, lic;
}id;
id D[(int)1e5+10];
int cmp(const void *_a,const void *_b)
{
    id a = *(id*)_a;
    id b = *(id*)_b;
    if(a.adm > b.adm) return 1;
    else if(a.adm == b.adm)
    {
        if(a.lic > b.lic) return 1;
        else if(a.lic == b.lic)
        {
            if(a.idx > b.idx) return 1;
        }
    }
    return 0;//不能是else return 0; 因為這樣僅會幫第一層的else回傳0其他層的不會 而造成錯誤
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&D[i].adm,&D[i].lic);
        D[i].idx = i+1;
    }
    qsort(D,n,sizeof(D[0]),cmp);
    for(int i=0;i<n;i++) printf("%d%c",D[i].idx," \n"[i == n-1]);
    return 0;
}
