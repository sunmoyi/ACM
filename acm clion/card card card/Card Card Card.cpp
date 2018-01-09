//
// Created by 孙启龙 on 2017/9/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

int a[maxn], b[maxn];
bool vis[maxn];

int main (void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &b[i]);

        int st = 1, ma = 0, ans = 0;
        while(!vis[n])
        {
            int sum = 0;
            int cnt = 0;
            int temp;
            for(int i = 0; i < n; i++)
            {
                temp = st + i;
                if(temp > n)
                    temp -= n;
                vis[temp] = true;
                cnt += a[temp];
                sum += a[temp];
                if(sum >= b[temp])
                    sum -= b[temp];
                else
                    break;
            }
            if(cnt > ma)
                ma = cnt, ans = st - 1;
            st = temp + 1;
        }
        printf("%d\n", ans);
    }
}