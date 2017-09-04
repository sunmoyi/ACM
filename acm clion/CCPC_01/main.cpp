#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 20
#define maxnum 1000000000
#define maxm 140000

using namespace std;

int a[maxn];
int dp[37][maxm];
int num[37];

long long cal(int len, int k) {
    long long now = 0;
    for (int i = 0; i < len; i++)
        now = now * k + a[i];
    return now;
}

long long f(long long n, int jz) {
    int len = 0;
    while (n) {
        num[len++] = n % jz;
        n /= 10;
    }
    num[len] = 0;
    return 1;
}

bool find_number(int k, int len, int lenn) {
    if (lenn >> 1 == len) {
        bool co = false;
        for (int i = (lenn + 1) >> 1; i < lenn; i++)
            a[i] = a[lenn - i - 1];
        long long now = cal(lenn, k);
        if (now > maxnum)
            co = true;
        else
            dp[k][num[k]++] = now;
        return co;
    } else if (len == lenn) {
        for (int i = 1; i < k; i++) {
            a[lenn - len] = i;
            if (find_number(k, len - 1, lenn))
                return true;
        }
    } else {
        for (int i = 0; i < k; i++) {
            a[lenn - len] = i;
            if (find_number(k, len - 1, lenn))
                return true;
        }
    }
    return false;
}

long long init(int n, int k) {
    if (n == 0)
        return 0;
    long long ans = n;
    int pos = upper_bound(dp[k], dp[k] + num[k], n) - dp[k] - 1;
    return ans + (long long) (pos + 1) * (k - 1);
}

void solve(int cnt) {
    long long ans = 0;
    int L, R, l, r;
    scanf("%d %d %d %d", &L, &R, &l, &r);
    for (int i = l; i <= r; i++)
        ans += init(R, i) - init(L - 1, i);
    printf("Case #%d: %lld\n", cnt, ans);
    return;
}

void yu()
{
    for (int i = 2; i <= 36; i++)
        for (int len = 1;; len++)
            if (find_number(i, len, len))
                break;
}

int main() {
    yu();
    int Case;
    int cnt = 0;
    scanf("%d", &Case);
    while (Case--)
        solve(++cnt);
    return 0;
}