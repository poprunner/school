#include <stdio.h>
int t, n, r, k, less, eqmore;
int map[1010], visited[510];    //even:x odd:y
int dfs(int now)
{
    int memcnt = 0;             //累積成員數
    visited[now] = 1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;
        if((map[i*2]-map[now*2])*(map[i*2]-map[now*2]) +
        (map[i*2+1]-map[now*2+1])*(map[i*2+1]-map[now*2+1]) <= r*r)
                memcnt += dfs(i);   //若同組將其回傳值加到累積成員數中
    }
    return 1 + memcnt;  //回傳 同組人數 + 自身
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&r,&k);
        for(int i=0;i<n;i++) scanf("%d%d",&map[i*2],&map[i*2+1]);
        for(int i=0;i<n;i++)
            if(!visited[i])
            {
                if(dfs(i) < k) less++;      //若同組人數少於 k less++
                else eqmore++;              //否則 eqmore++
            }
        printf("%d %d\n",less,eqmore);

        less = 0, eqmore = 0;               //歸0
        for(int i=0;i<n;i++) visited[i] = 0;
    }
    return 0;
}
