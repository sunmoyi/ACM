//
// Created by 孙启龙 on 2016/11/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20
#define INF 0x3f3f3f3f

using namespace std;

int n, a[maxn][maxn], b[maxn][maxn];

int check(int s)
{

    memset(b, 0, sizeof(b));
    for(int c = 0; c < n; c++)
    {
        //printf("%d %d %d\n", s, c, s & (1 << c));
        if(s & (1 << c))
            b[0][c] = 1;
        else if (a[0][c] == 1)
            return INF;
    }
    //printf("%d\n", s);
    for(int r = 1; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            int sum = 0;
            if(r > 1)
                sum += b[r - 2][c];
            if(c > 0)
                sum += b[r - 1][c - 1];
            if(c < n - 1)
                sum += b[r - 1][c + 1];
            b[r][c] = sum % 2;
            //printf("%d %d %d \n", r, c, b[r][c]);
            if(a[r][c] == 1 && b[r][c] == 0)
                return INF;
        }
    }
    //printf("\n\n\n");
    int cnt = 0;
    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++)
            if(a[r][c] != b[r][c])
                cnt++;
    return cnt;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case ++)
    {
        scanf("%d", &n);
        for(int r = 0; r < n; r++)
            for(int c = 0; c < n; c++)
                scanf("%d", &a[r][c]);
        int ans = INF;
        for(int s = 0; s < (1 << n); s++)
            ans = min(ans, check(s));
        if(ans == INF)
            ans = -1;
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
