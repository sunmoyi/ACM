//
// Created by 孙启龙 on 2017/9/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>

using namespace std;
char s[6][22], ss[22];
const int maxn = 1000 + 10;
const int mod = 998244353;
const int CH = 3;
int t, n, L, dp[101][maxn][128];

struct Trie {
    int nxt[maxn][CH], fail[maxn], end[maxn], isEnd[maxn];
    int root, L;

    void init() {
        L = 0;
        root = newnode();
    }

    int newnode() {
        for (int i = 0; i < CH; i++)
            nxt[L][i] = -1;
        isEnd[L] = 0;
        end[L++] = 0;
        return L - 1;
    }

    void insert(char buf[], int len, int idx, bool flg) {
        int p = root;
        for (int i = 0; i < len; i++) {
            if (nxt[p][buf[i]] == -1)
                nxt[p][buf[i]] = newnode();
            p = nxt[p][buf[i]];
        }
        if (flg)
            isEnd[p] |= (1 << idx);
        else
            end[p] |= (1 << idx);
        isEnd[p] |= (1 << idx);
    }

    void build() {
        queue<int> que;
        fail[root] = root;
        for (int i = 0; i < CH; i++)
            if (nxt[root][i] == -1)
                nxt[root][i] = root;
            else
                fail[nxt[root][i]] = root,
                        que.push(nxt[root][i]);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            for (int i = 0; i < CH; i++)
                if (nxt[p][i] == -1)
                    nxt[p][i] = nxt[fail[p]][i];
                else {
                    fail[nxt[p][i]] = nxt[fail[p]][i];
                    que.push(nxt[p][i]);
                }
        }
    }
} ac;

void jugGapAndInsert(int idx, int gap) {
    for (int i = 0;; i++) {
        if (gap + i + 1 == strlen(s[idx]) || gap - i < 0)
            break;
        if (s[idx][gap + i + 1] == s[idx][gap - i])
            return;
    }
    int len = strlen(s[idx]);
    if (gap + 1 > len - gap - 1) {
        ac.insert(s[idx], gap + 1, idx, true);
    } else {
        for (int i = 0; i < len - gap - 1; i++)
            ss[i] = 3 - s[idx][len - i - 1];
        ac.insert(ss, len - gap - 1, idx, true);
    }
}

int main() {
    scanf("%d", &t);
    while (t-- && scanf("%d %d", &n, &L) != EOF) {
        ac.init();
        memset(dp, 0, sizeof(dp));
        for (int i = 0, len; i < n; i++) {
            scanf(" %s", s[i]);
            len = strlen(s[i]);
            for (int j = 0; j < len; j++) {
                s[i][j] = s[i][j] - '0' + 1;
                ss[len - j - 1] = 3 - s[i][j];
            }
            ac.insert(s[i], len, i, false);
            ac.insert(ss, len, i, false);
            for (int j = 0; j < len - 1; j++)
                jugGapAndInsert(i, j);
        }
        ac.build();

        dp[0][0][0] = 1;
        for (int i = 0, nxt, tmpNxt, status, isEnd; i < L; i++)
            for (int j = 0; j < ac.L; j++)
                for (int c = 1; c <= 2; c++) {
                    nxt = j;
                    status = 0, isEnd = 0;
                    nxt = ac.nxt[nxt][c];
                    tmpNxt = nxt;
                    while (tmpNxt != 0) {
                        status |= ac.end[tmpNxt];
                        if (i + 1 == L)
                            status |= ac.isEnd[tmpNxt];
                        tmpNxt = ac.fail[tmpNxt];
                    }

                    for (int S = 0; S < (1 << n); S++)
                        (dp[i + 1][nxt][S | status] += dp[i][j][S]) %= mod;
                }
        long long ans = 0;
        for (int j = 0; j < ac.L; j++)
            (ans += dp[L][j][(1 << n) - 1]) %= mod;
        printf("%lld\n", ans);
    }
}