//
// Created by 孙启龙 on 2017/8/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

#define INF 0x3f3f3f3f
#define maxn 555555

int T, n, no, ch[maxn][26], id[maxn], cnt[maxn], sum[maxn], ans, Pre, Next;
char c[maxn], s[maxn];

void init() {
    memset(ch[0], -1, sizeof(ch[0]));
    cnt[0] = 0, id[0] = -1, no = 0;
}

void insert(char *s, int _id) {
    int u = 0;
    cnt[0]++;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (ch[u][c] == -1) {
            ch[u][c] = ++no;
            memset(ch[no], -1, sizeof(ch[no]));
            cnt[no] = 0, id[no] = -1;
        }
        u = ch[u][c];
        cnt[u]++;
    }
    id[u] = _id;
}

void dfs(int l, int r, int u, int pre, int next, int deep) {
    if (l == r) {
        ans = min(ans, deep), Pre = pre, Next = next + cnt[u] - 1;
        return;
    }
    int c = s[l] - 'a', tpre = pre, tnext = next;
    for (int i = 0; i < c; i++)
        if (ch[u][i] != -1)
            tpre += cnt[ch[u][i]];
    if (id[u] != -1)
        tpre++;
    for (int i = c + 1; i < 26; i++)
        if (ch[u][i] != -1)
            tnext += cnt[ch[u][i]];
    dfs(l + 1, r, ch[u][c], tpre, tnext, deep + 1);
    ans = min(ans, deep + Pre - pre), ans = min(ans, deep + 1 + Next - next);
}

void Solve(int l, int r) {
    ans = INF, Pre = 0, Next = 0;
    dfs(l, r, 0, 0, 0, 1);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", c);
            int len = strlen(c);
            insert(c, i);
            sum[i] = sum[i - 1] + len;
            for (int j = sum[i - 1]; j < sum[i]; j++)
                s[j] = c[j - sum[i - 1]];
        }
        for (int i = 1; i <= n; i++) {
            Solve(sum[i - 1], sum[i]);
            printf("%d%c", ans, i == n ? '\n' : ' ');
        }
    }
    return 0;
}