//
// Created by 孙启龙 on 2017/5/14.
//

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define maxn 510
//
//using namespace std;
//
//struct node{
//    int high, maxhigh, sum;
//    bool friend operator < (const node&a, const node&b)
//    {
//        return a.maxhigh < b.maxhigh;
//    }
//}stone[maxn];
//int used[400010], n;
//bool dp[400010];
//
//int main (void)
//{
//    while(scanf("%d", &n) != EOF)
//    {
//        for (int i = 1; i <= n; i++)
//            scanf("%d %d %d", &stone[i].high, &stone[i].maxhigh, &stone[i].sum);
//        sort(stone + 1, stone + n + 1);
//
//        dp[0] = true;
//        int ans = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            memset(used, 0, sizeof(used));
//            for (int now = stone[i].high; now <= stone[i].maxhigh; now++)
//            {
//                if (!dp[now] && dp[now - stone[i].high] && used[now - stone[i].high] < stone[i].sum)
//                {
//                    dp[now] = true;
//                    used[now] = used[now - stone[i].high] + 1;
//                    ans = max(ans, now);
//                }
//            }
//
//        }
//        printf("%d\n", ans);
//    }
//    return 0;
//}

#include <cstdio>
#include <cstring>
#include <algorithm>
#define  max(a,b)  a>b ? a:b

using namespace std;

const int maxn = 410;
int dp[40010];
struct node {
    int h, a, c;
    bool operator <(const node& rhs) const {
        return a< rhs.a;
    }
}f[maxn];

void CompletePack(int C, int W, int V)
{
    for(int i=C; i<=V; i++)
        dp[i] = max(dp[i],dp[i-C]+W);
}

void ZeroOnePack(int C, int W, int V)
{
    for(int i=V; i>=C; i--)
        dp[i] = max(dp[i], dp[i-C]+W);
}

void MultipliePack(int C, int W, int M, int V)
{
    if(C*M >=V) {
        CompletePack(C,W,V);
        return ;
    }
    int k=1;
    while(k<M) {
        ZeroOnePack(k*C,k*W,V);
        M -=k;
        k <<=1;
    }
    ZeroOnePack(C*M,W*M,V);
}

int main()
{
    int k, n, i, j, ans, maxH;
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
        {
            scanf("%d%d%d",&f[i].h,&f[i].a,&f[i].c);
        }
        sort(f,f+n);
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++)
        {
            MultipliePack(f[i].h,f[i].h,f[i].c,f[i].a);
        }
        maxH  = 0;
        for(i=f[n-1].a; i>=0; i--)
            if(maxH < dp[i]) maxH = dp[i];
        printf("%d\n",maxH);
    }
    return 0;
}