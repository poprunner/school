#include <stdio.h>
int x[1010], y[1010], visited[1010], n, r, member;
void dfs(int now)
{
    visited[now] = 1;
    member++;
    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;
        if((x[i]-x[now])*(x[i]-x[now]) + (y[i]-y[now])*(y[i]-y[now]) <= r*r) dfs(i);
    }
}
int main()
{
    int single = 0, group = 0;
    scanf("%d%d",&n,&r);
    for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=0;i<n;i++)
        if(!visited[i])
        {
            dfs(i);
            if(member == 1) single++;
            else group++;
            member = 0;
        }
    printf("%d %d\n",single,group);
    return 0;
}
