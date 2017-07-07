//
// Created by 孙启龙 on 2016/10/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, deep;
char s[10] = "AGCT";

struct node{
    char s[10];
    int len;
}a[10];
int pos[10];

int get_h()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, a[i].len - pos[i]);
    return ans;
}

int dfs(int step)
{
    if(step + get_h() > deep)
        return 0;
    if(!get_h())
        return 1;
    int i, j;
    int temp[10];
    for(int i = 0; i < 4; i++)
    {
        int flag = 0;
        for(int j = 1; j <= n; j++)
            temp[j] = pos[j];
        for(int j = 1; j <= n; j++)
        {
            if(a[j].s[pos[j]] == s[i])
            {
                flag = 1;
                pos[j]++;
            }
        }
        if(flag)
        {
            if(dfs(step + 1))
                return 1;
            for(int j = 1; j <= n; j++)
                pos[j] = temp[j];
        }
    }
    return 0;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int maxn = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", a[i].s);
            a[i].len = strlen(a[i].s);
            maxn = max(maxn, a[i].len);
            pos[i] = 0;
        }
        deep = maxn;
        while(1)
        {
            if(dfs(0))
                break;
            deep++;
        }
        printf("%d\n", deep);
    }
    return 0;
}