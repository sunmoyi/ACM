//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
#define move 100000
using namespace std;

int n, t, x;
int timee[maxn];
bool vis[maxn << 3];
bool flag = false;
int ans = 0;
int main(void)
{
    scanf("%d %d %d", &n, &t, &x);
    for(int i = 1; i <= n; i++)
        scanf("%d", &timee[i]);
    memset(vis, false, sizeof(vis));
    for(int i = n; i >= 1; i--)
    {
        int nowtime = timee[i];
        int num = 0;
        for(int j = nowtime - t; j <= nowtime - 1; j++)
        {
            if(vis[j + move])
                num++;
        }
        if(num < x)
        {
            for(int j = nowtime - t; j <= nowtime - 1; j++)
            {
                if(!vis[j + move])
                {
                    vis[j + move] = true;
                    ans++;
                    num++;
                }
                if(num == x)
                    break;
            }
            if(num < x)
            {
                flag = true;
                break;
            }
        }
    }
    if(flag)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}