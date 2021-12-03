#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[1010][1010];
int cmp(const void *_a,const void *_b)
{
    char *a = (char*)_a;
    char *b = (char*)_b;
    return strlen(a) > strlen(b);//要字串長度相比 用strcmp可能會因字串內容干擾造成排序錯誤
}
int main()
{
    int n, i, yes = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",str[i]);
    qsort(str,n,sizeof(str[0]),cmp);
    for(i=0;i<n-1;i++)
        if(strstr(str[i+1],str[i]) == NULL){yes = 0; break;}
    if(yes)
    {
        printf("YES\n");
        for(i=0;i<n;i++) printf("%s\n",str[i]);
    }
    else printf("NO\n");
    return 0;
}
