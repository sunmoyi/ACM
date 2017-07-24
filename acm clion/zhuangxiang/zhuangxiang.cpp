//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn];
int n, maxx;
int ans;

bool cmp(int a, int b)
{
    return a > b;
}

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        scanf("%d", &maxx);
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);

        sort(num + 1, num + n + 1, cmp);

        int now = 1;
        ans = 0;
        while(now <= n)
        {
            if(now != n && num[now] + num[n] <= maxx)
                n--;
            ans++;
            now++;
        }
        printf("%d\n", ans);
    }
    return 0;
}