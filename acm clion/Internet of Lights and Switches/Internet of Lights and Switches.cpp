//
// Created by 孙启龙 on 2017/4/26.
//

#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define FIN             freopen("input.txt","r",stdin)
#define fst             first
#define snd             second

typedef long long  LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const double eps = 1e-10;

const int MAXN = 50 + 5;
const int MAXM = 300000 + 5;
const int INF  = 0x3f3f3f3f;

int  N, M, A, B;
char buf[MAXN];
LL pre[MAXM], X, Y, E;
PLL data[MAXM];
LL F (char s[]) {
    LL ret = 0LL;
    for (int i = 0; s[i]; i++) {
        ret = (ret << 1) + s[i] - '0';
    }
    return ret;
}
int main()
{

    int cas = 0;
    LL res;
    while (~scanf ("%d %d %d %d", &N, &M, &A, &B) ) {
        res = E = pre[0] = 0LL;
        for (int i = 1; i <= N; i++) {
            E = (E << 1) | 1;
        }
        data[0] = PLL (0, 0);
        for (int i = 1; i <= M; i++) {
            scanf ("%s", buf);
            X = F (buf);
            pre[i] = pre[i - 1] ^ X;
            data[i].fst = pre[i];
            data[i].snd = i;
        }
        sort (data, data + M + 1);
        for (int i = 0; i <= M; i++) {
            X = data[i].fst;
            Y = data[i].snd;
            int a = lower_bound (data + 1, data + M + 1, PLL (X ^ E, Y + A) ) - data;
            int b = upper_bound (data + 1, data + M + 1, PLL (X ^ E, Y + B) ) - data;
            if (a > M) continue;
            res += (b - a);
        }
        printf ("Case %d: %I64d\n", ++cas, res);
    }
    return 0;
}