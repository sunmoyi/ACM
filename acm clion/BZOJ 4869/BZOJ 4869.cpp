//
// Created by 孙启龙 on 2017/7/29.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<set>

using namespace std;

const int maxn = 5E4 + 5;
typedef long long LL;

int n, m, p, c, tot, A[maxn], B[maxn], C[maxn];
LL sum[maxn], s[maxn];

set<int> st;
stack<int> stk;
set<int>::iterator it;

inline int ksm(LL x, int y, LL Mod, bool &bo) {
    LL ret = 1;
    bo = 0;
    for (; y; y >>= 1) {
        if (y & 1) {
            bo |= ((ret *= x) >= Mod);
            ret %= Mod;
        }
        bo |= ((x *= x) >= Mod);
        x %= Mod;
    }
    return ret;
}

inline void Modify(int k) {
    LL delta = -B[k];
    bool bo = 0;
    ++C[k];
    if (C[k] > tot) {
        stk.push(k);
        return;
    }
    int now = C[k] == 1 ? A[k] : ksm(c, A[k], s[C[k]], bo);
    if (bo)
        now += s[C[k]];
    for (int i = C[k] - 1; i > 1; i--) {
        now = ksm(c, now, s[i], bo);
        if (bo)
            now += s[i];
    }
    now = ksm(c, now, p, bo);
    delta += now;
    B[k] = now;
    for (int i = k; i <= n; i += i & -i)
        sum[i] += delta;
}

inline void Find(int x) {
    s[++tot] = x;
    if (x == 1)
        return;
    int Sqrt = sqrt(x), phi = 1;
    for (int i = 2; i <= Sqrt; i++) {
        if (x % i != 0)
            continue;
        phi *= (i - 1);
        x /= i;
        while (x % i == 0)
            x /= i, phi *= i;
    }
    if (x > 1)
        phi *= (x - 1);
    Find(phi);
}

inline int getint() {
    char ch = getchar();
    int ret = 0;
    while (ch < '0' || '9' < ch)
        ch = getchar();
    while ('0' <= ch && ch <= '9')
        ret = ret * 10 + ch - '0', ch = getchar();
    return ret;
}

int main() {
    n = getint();
    m = getint();
    p = getint();
    c = getint();
    Find(p);
    s[++tot] = 1;
    for (int i = 1; i <= n; i++) {
        A[i] = B[i] = getint();
        st.insert(i);
        for (int j = i; j <= n; j += j & -j)
            sum[j] += 1LL * A[i];
    }
    st.insert(n + 1);
    while (m--) {
        int typ = getint(), l, r;
        l = getint();
        r = getint();
        if (!typ) {
            for (it = st.lower_bound(l); (*it) <= r; it++)
                Modify(*it);
            while (!stk.empty())
                st.erase(stk.top()), stk.pop();
        } else {
            LL Ans = 0;
            for (int i = r; i > 0; i -= i & -i)
                Ans += sum[i];
            for (int i = l - 1; i > 0; i -= i & -i)
                Ans -= sum[i];
            Ans %= p;
            printf("%d\n", (int) (Ans + p) % p);
        }
    }
    return 0;
}