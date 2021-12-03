#include <stdio.h>
typedef struct{
    int hp, atk;
}mon;
mon a[10][10];
int visited[10][10], tox[] = {1,-1,0,0}, toy[] = {0,0,1,-1};
int dfs(int hhp,int hatk,int i,int j)
{
    visited[i][j] = 1;
    hhp -= ((a[i][j].hp-1)/hatk)*a[i][j].atk;
    if(hhp <= 0) return 0;
    if(i == 5 && j == 5) return 1;
    for(int t=0;t<4;t++)
    {
        if(i+tox[t]<1 || i+tox[t]>5 || j+toy[t]<1 || j+toy[t]>5
            || visited[i+tox[t]][j+toy[t]]) continue;
        if(dfs(hhp,hatk,i+tox[t],j+toy[t])) return 1;   //若成功傳捷報一路傳回去
        visited[i+tox[t]][j+toy[t]] = 0;
    }
    return 0;
}
int main()
{
    int hhp, hatk, k, mhp, matk, mx, my;
    scanf("%d%d%d",&hhp,&hatk,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d%d%d",&mhp,&matk,&mx,&my);
        a[mx][my].hp = mhp;
        a[mx][my].atk = matk;
    }
    if(dfs(hhp,hatk,1,1)) printf("HEIR OF FIRE DESTROYED\n");
    else printf("YOU DIED\n");
    return 0;
}
