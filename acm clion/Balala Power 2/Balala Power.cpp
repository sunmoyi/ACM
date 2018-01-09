//
// Created by 孙启龙 on 2017/8/27.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
ll fac[maxn] = {1};
int Hash[27];
bool lead[27];
char str[maxn];

void init() {
    for (int i = 1; i < maxn; i++)
        fac[i] = fac[i - 1] * 26 % mod;
}

struct node {
    int cnt[maxn];
    int id;

    bool operator<(const node &a) const {
        for (int i = maxn - 1; i >= 0; i--) {
            if (cnt[i] > a.cnt[i])
                return 1;
            else if (cnt[i] < a.cnt[i])
                return 0;
            else;
        }
    }
} a[27];

int main(void) {
    int n, ca = 1;
    init();
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        memset(Hash, -1, sizeof(Hash));
        memset(lead, 0, sizeof(lead));
        for (int i = 1; i <= n; i++) {
            scanf(" %s", str);
            int len = strlen(str);
            if (len != 1)
                lead[str[0] - 'a'] = 1;
            for (int j = 0; j < len; j++)
                a[str[j] - 'a'].cnt[len - j - 1]++;
        }
        //进位操作，满26个等与一个下一位
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < maxn; j++) {
                if (a[i].cnt[j] >= 26) {
                    a[i].cnt[j + 1] += a[i].cnt[j] / 26;
                    a[i].cnt[j] %= 26;
                }
            }
            a[i].id = i;
        }
        sort(a, a + 26);
        for (int i = 0; i < 26; i++)
            Hash[a[i].id] = 26 - i - 1;
        for (int i = 0; i < 26; i++) //前导0找最小的可以做0的位来放0
            if (lead[a[i].id] && Hash[a[i].id] == 0) {
                for (int j = 25; j >= 0; j--) {
                    if (!lead[a[j].id]) {
                        for (int k = 25; k >= j + 1; k--)
                            Hash[a[k].id] = Hash[a[k - 1].id];
                        Hash[a[j].id] = 0;
                        break;
                    }
                }
                break;
            }
        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < maxn; j++) {
                ans = (ans + fac[j] * a[i].cnt[j] * Hash[a[i].id] % mod) % mod;
            }
        }
        printf("Case #%d: %lld\n", ca++, ans);
    }
    return 0;
}