//
// Created by 孙启龙 on 2017/3/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define INF 0x3f3f3f3f

using namespace std;

int n, a[maxn], b[maxn];

int solve()
{
    int ans = 0, minn = INF;
    for(int i = 1; i <= n; i++)
    {
        ans = 0;
        memcpy(b, a, sizeof(a));
        for(int j = 0; j < n && ans < minn; j++)
        {
            int index = i + j;
            if(b[index] != j + 1)
            {
                ans++;
                for(int k = index; k < i + n; k++)
                {
                    if(b[k] == j + 1)
                        b[k] = b[index];
                }
            }
        }
        minn = min(minn, ans);

        ans = 0;
        memcpy(b, a, sizeof(a));
        for(int j = 0; j < n && ans < minn; j++)
        {
            int index = i + n - j;
            if(b[index] != j + 1)
            {
                ans++;
                for(int k = index; k > i; k--)
                {
                    if(b[k] == j + 1)
                        b[k] = b[index];
                }
            }
        }
        minn = min(minn, ans);
    }
    return ans;
}

int main (void)
{
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            a[i + n] = a[i];
        }
        printf("%d\n", solve());
    }
    return 0;
}