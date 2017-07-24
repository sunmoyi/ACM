//
// Created by 孙启龙 on 2017/3/25.
//

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 30;

int vis[maxn];

int n, m;

int main()
{
    //freopen("D:\\txt.txt", "r", stdin);
    int x;
    while (~scanf("%d%d",&n,&m) && n && m)
    {
        int x;
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            ans += x;
            vis[x]++;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &x);
            if (!vis[x])   ans += x;
            else  vis[x]--;
        }
        printf("%d\n", ans);
    }
}