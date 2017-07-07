//
// Created by 孙启龙 on 2016/11/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20005

using namespace std;

int a[maxn], b[maxn];

int main (void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF && n && m)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int j = 0; j < m; j++)
            scanf("%d", &b[j]);
        sort(a, a + n);
        sort(b, b + m);

        int cur = 0;
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            if(b[i] >= a[cur])
            {
                ans += b[i];
                if(++cur == n)
                    break;
            }
        }
        if(cur < n)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}