//
// Created by 孙启龙 on 2017/8/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 5e5 + 10;
typedef long long LL;

int pre[N], nxt[N], v[N], pos[N], n, k;

LL a[N], b[N];

LL solve(int x) {
    int c1 = 0, c2 = 0;
    for (int i = x; i && c1 <= k; i = pre[i])
        a[++c1] = i - pre[i];
    for (int i = x; i <= n && c2 <= k; i = nxt[i])
        b[++c2] = nxt[i] - i;
    LL ans = 0;
    for (int i = 1; i <= c1; i++)
        if (k - i + 1 <= c2 && k - i + 1 >= 1)
            ans += a[i] * b[k - i + 1];
    return ans;
}

void del(int x) {
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &v[i]), pos[v[i]] = i;
        for (int i = 0; i <= n + 1; i++)
            pre[i] = i - 1, nxt[i] = i + 1;
        pre[0] = 0;
        nxt[n + 1] = n + 1;
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += solve(pos[i]) * i;
            del(pos[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}