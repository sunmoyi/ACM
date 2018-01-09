//
// Created by 孙启龙 on 2017/8/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

namespace IO {
    const int MX = 4e7; //1e7占用内存11000kb
    char buf[MX];
    int c, sz;

    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }

    inline bool read(int &t) {
        while (c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9'))
            c++;
        if (c >= sz)
            return false;
        bool flag = 0;
        if (buf[c] == '-')
            flag = 1, c++;
        for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++)
            t = t * 10 + buf[c] - '0';
        if (flag)
            t = -t;
        return true;
    }
}
const long long mod = 1e9 + 7;
const int MX = 1e6 + 5;
long long F[MX], invF[MX];

long long power(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void init() {
    F[0] = 1;
    for (int i = 1; i < MX; i++)
        F[i] = F[i - 1] * i % mod;
    invF[MX - 1] = power(F[MX - 1], mod - 2);
    for (int i = MX - 2; i >= 0; i--)
        invF[i] = invF[i + 1] * (i + 1) % mod;
}

long long C(long long n, long long m) {
    long long ret = 1;
    while (n && m) {
        long long nn = n % mod, mm = m % mod;
        if (nn < mm)
            return 0;
        ret = ((ret * F[nn] % mod) * invF[mm] % mod) * invF[nn - mm] % mod;
        n /= mod, m /= mod;
    }
    return ret;
}

struct node {
    int l, r, id;

    bool operator<(const node &_A) const {
        if (l != _A.l)
            return l < _A.l;
        return r > _A.r;
    }
} a[MX];

int n;
int mark;  //是否有区间不合法
int rear;

long long dfs(int l, int r) {
    if (mark == 0)
        return 0;
    if (l > r)
        return 1;
    if (a[rear].l != l || a[rear].r != r) {
        mark = 0;
        return 0;
    }
    node now = a[rear++];
    long long ret = ((C(now.r - now.l, now.id - now.l) * dfs(now.l, now.id - 1) % mod) * dfs(now.id + 1, now.r)) % mod;
    return ret;
}

int main() {
    int cas = 0;
    init();
    IO::begin();
    while (IO::read(n)) {
        for (int i = 1; i <= n; i++)
            IO::read(a[i].l);
        for (int i = 1; i <= n; i++)
            IO::read(a[i].r), a[i].id = i;
        sort(a + 1, a + n + 1);
        mark = rear = 1;
        printf("Case #%d: %lld\n", ++cas, dfs(1, n));
    }
    return 0;
}