#include <stdio.h>
int n;
int tree[1024];
void prin(int now)
{
    if(now > n) return;     //超過範圍直接return
    prin(now*2);
    printf("%d%c",tree[now]," \n"[now == n]);//若是最後一個(第n個) 改印換行
    prin(now*2+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&tree[i]);
    prin(1);
    return 0;
}
