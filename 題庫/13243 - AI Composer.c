#include <stdio.h>
#include <string.h>
char s[5010], t[5010];
//我是87 left right 應該要用int 結果我用成char 害我多浪費一小時 ==
int left[5010], right[5010];
int T, n, m, block, t_position;
int search()
{
    int i, j, cnt = 0, max = 0, l, r, r_tmp, l_tmp;
    for(i=n-1;i>=0;i--)
    {
        cnt = 0;
        l_tmp = i+2;
        for(j=0;i-j>=0;j++)
        {
            if(s[i-j] == t[t_position+j])
            {
                cnt++;
                l_tmp --;
            }
            else break;
        }
        if(cnt >= max)
        {
            max = cnt;
            l = i+1;
            r = l_tmp;
        }
    }
    for(i=0;i<n;i++)
    {
        cnt = 0;
        r_tmp = i;
        for(j=0;i+j<n;j++)
        {
            if(s[i+j] == t[t_position+j])
            {
                cnt++;
                r_tmp ++;
            }
            else break;
        }
        if(cnt >= max)
        {
            max = cnt;
            l = i+1;
            r = r_tmp;
        }
    }
    if(max > 0)
    {
        left[block] = l;
        right[block] = r;
        block++;
        t_position += max;
        return 0; 
    }
    else return -1;
}
int main()
{
    int fail;
    scanf("%d",&T);
    while(T--)
    {
        fail = 0, block = 0, t_position = 0;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        scanf("%d%s",&n,s);
        scanf("%d%s",&m,t);
        while(t_position < m)
        {
            if(search() == -1)
            {
                fail = 1;
                break;
            }
        }
        if(fail) printf("-1\n");
        else
        {
            printf("%d\n",block);
            for(int i=0;i<block;i++) printf("%d %d\n",left[i],right[i]);
        }
    }
    return 0;
}



// TLE
/*
#include <stdio.h>
char s[3010], t[3010], left[3010], right[3010], t_left[3010], t_right[3010];
int T, n, m, block = 3010, fail;
void search(int t_position,int t_block)
{   
    int i, j, cnt = 0, l, r, r_tmp, l_tmp;
    if(t_position == m)
    {
        if(t_block < block)
        {
            block = t_block;
            for(i=0;i<block;i++)
            {
                left[i] = t_left[i];
                right[i] = t_right[i];
            }
            fail = 0;
        }
        return;
    }
 
    for(i=0;i<n;i++)
    {
        cnt = 0;
        r_tmp = i;
        for(j=0;i+j<n;j++)
        {
            if(t_position+j == m) break;
            if(s[i+j] == t[t_position+j])
            {
                cnt++;
                r_tmp ++;
            }
            else break;
        }
        if(cnt > 0)
        {
            t_left[t_block] = i+1;
            t_right[t_block] = r_tmp;
            search(t_position+cnt,t_block+1);
        }
    }
    for(i=n-1;i>=0;i--)
    {
        cnt = 0;
        l_tmp = i+2;
        for(j=0;i-j>=0;j++)
        {
            if(t_position+j == m) break;
            if(s[i-j] == t[t_position+j])
            {
                cnt++;
                l_tmp --;
            }
            else break;
        }
        if(cnt > 0)
        {
            t_left[t_block] = i+1;
            t_right[t_block] = l_tmp;
            search(t_position+cnt,t_block+1);
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        fail = 1, block = 3010;

        scanf("%d%s",&n,s);
        scanf("%d%s",&m,t);
        search(0,0);
        if(fail) printf("-1\n");
        else
        {
            printf("%d\n",block);
            for(int i=0;i<block;i++) printf("%d %d\n",left[i],right[i]);
        }
    }
    return 0;
}*/
