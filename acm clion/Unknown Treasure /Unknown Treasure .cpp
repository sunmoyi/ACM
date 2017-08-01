//
// Created by 孙启龙 on 2017/7/30.
//

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<stack>
#include<vector>

#define LL long long
#define MAXN 1000010
using namespace std;
const int N = 20;//模方程数
LL a[N], mod[N];

LL mul(LL a, LL b, LL mod)//a*b%mod
{
    LL ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ans;
}

LL quick_mod(LL a, LL b, LL m)//a^b%m
{
    LL ans = 1;
    a %= m;
    while (b) {
        if (b & 1) {
            ans = ans * a % m;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

LL getC(LL n, LL m, int cur)//C(n,m)%mod[cur]
{
    LL p = mod[cur];
    if (m > n)
        return 0;
    if (m > n - m)
        m = n - m;
    LL ans = 1;
    for (int i = 1; i <= m; i++) {
        LL a = (n + i - m) % p;
        LL b = i % p;
        //ans=mul(ans,mul(a,quick_mod(b,p-2,p),p),p);//p为素数，i对p的逆元可以不用扩张欧几里得进行求解  re=i^(P-2)
        ans = ans * (a * quick_mod(b, p - 2, p) % p) % p;
    }
    return ans;
}

LL Lucas(LL n, LL k, int cur)//求C(n,k)%mod[cur]
{
    LL p = mod[cur];
    if (k == 0)
        return 1 % p;
    //return getC(n%p,k%p,cur)*Lucas(n/p,k/p,cur)%p;
    return getC(n % p, k % p, cur) * Lucas(n / p, k / p, cur) % p;
}

void extend_Euclid(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    extend_Euclid(b, a % b, x, y);
    LL tmp = x;
    x = y;
    y = tmp - a / b * y;
}

LL CRT(LL a[], LL m[], int k)//求C(n,m)%M,其中M=(m0*m2*…*m(k-1)),mi为素数，则先用a[i]存储模方程C(n,m)%mi,
{                           //m[]存储所有素数因子mi，k表示总共有k个模方程，返回C(n,m)%M的值
    LL M = 1;
    LL ans = 0;
    for (int i = 0; i < k; i++)
        M *= mod[i];
    for (int i = 0; i < k; i++) {
        LL x, y, tmp;
        LL Mi = M / m[i];
        extend_Euclid(Mi, m[i], x, y);
        if (x < 0) {
            x = -x;
            tmp = mul(Mi, x, M);
            tmp = mul(tmp, a[i], M);
            tmp = -tmp;
        } else {
            tmp = mul(Mi, x, M);
            tmp = mul(tmp, a[i], M);
        }
        ans = (ans + tmp) % M;
    }
    while (ans < 0)
        ans += M;
    return ans;
}

int main() {
    //freopen("D:\\in.txt","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        LL n, m;
        int k;
        scanf("%lld%lld%d", &n, &m, &k);
        //k=1;
        for (int i = 0; i < k; i++)
            scanf("%lld", &mod[i]);
        for (int i = 0; i < k; i++)
            a[i] = Lucas(n, m, i) % mod[i];
        //printf("%I64d\n",a[0]);
        printf("%lld\n", CRT(a, mod, k));
    }
    return 0;
}