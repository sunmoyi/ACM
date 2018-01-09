//
// Created by 孙启龙 on 2017/9/23.
//


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 307
#define INF 0x3f3f3f3f

using namespace std;


int arr[maxn][maxn];
int a[maxn], b[maxn];
int f[maxn][2];
int n, m, p;
int ans = -INF;

void input()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &arr[i][j]);
}

void solve(int i)
{
    for (int j = i; j < n; j++)
    {
        for (int k = 0; k < m; k++) {
            b[k] = max(b[k] + arr[j][k], a[k] + p);
            a[k] += arr[j][k];
        }
        f[0][0] = a[0];
        if (i != 0 || j != n - 1 || m - 1)
            ans = max(ans, f[0][0]);
        f[0][1] = b[0];
        ans = max(ans, f[0][1]);
        bool flag = ((i == 0) & (j == n - 1));
        for (int k = 1; k < m; k++) {
            f[k][1] = max(f[k - 1][0] + b[k], max(b[k], f[k - 1][1] + a[k]));
            ans = max(ans, f[k][1]);
            if (f[k - 1][0] <= 0) {
                flag = false;
                f[k][0] = a[k];
            } else
                f[k][0] = f[k - 1][0] + a[k];
            if (flag && k == m - 1)
                continue;

            ans = max(ans, f[k][0]);
        }

    }
}

namespace fastIO {
#define BUF_SIZE 100000
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
#undef BUF_SIZE
};

int main()
{

    while (scanf("%d %d %d", &n, &m, &p) != EOF) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &arr[i][j]);
        ans = -INF;
        for (int i = 0; i < n; i++)
        {
            memset(a, 0, sizeof(a));
            memset(b, 0xf0, sizeof(b));
            solve(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}