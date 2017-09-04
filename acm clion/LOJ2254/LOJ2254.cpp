//
// Created by 孙启龙 on 2017/8/8.
//

/*
 * 题目描述
给你一个长度为 NNN 的序列 aia_ia
​i
​​ ，1≤i≤N1\leq i\leq N1≤i≤N，和 qqq 组询问，每组询问读入 l1,r1,l2,r2l_1,r_1,l_2,r_2l1,r1,l​2,r2
​，需输出∑x=0∞get(l1,r1,x)⋅get(l2,r2,x) \sum\limits_{x=0}^\infty \text{get}(l_1,r_1,x)\cdot \text{get}(l_2,r_2,x)
​x=0∑∞get(l1,r1,x)⋅get(l2,r2,x)
get(l,r,x) \text{get}(l,r,x)get(l,r,x) 表示计算区间 [l,r][l,r][l,r] 中，数字 xxx 出现了多少次。
输入格式
第一行，一个数字 NNN，表示序列长度。
第二行，NNN 个数字，表示 a1∼aNa_1\sim a_Na
​1∼a​N。
第三行，一个数字 QQQ，表示询问个数。
第 4∼Q+34\sim Q+34∼Q+3 行，每行四个数字 l1,r1,l2,r2l_1,r_1,l_2,r_2l​1,r1,l2,r2，表示询问。
输出格式
对于每组询问，输出一行一个数字，表示答案。
样例
样例输入

5
1 1 1 1 1
2
1 2 3 4
1 1 4 4
样例输出

4
1
 * */

#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define N 50010
#define ll long long

using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

struct zgz {
    int l, r, id, ty;
} q[N << 2];
int n, cnt;
int a[N], bl[N], blk;
int Q;
ll ans[N], sum = 0, s1[N], s2[N];

bool cmp(zgz a, zgz b) {
    return bl[a.l] == bl[b.l] ? a.r < b.r : bl[a.l] < bl[b.l];
}

int main() {
    n = read();
    blk = sqrt(n);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        bl[i] = (i - 1) / blk + 1;
    Q = read();
    for (int i = 1; i <= Q; i++) {
        int l1 = read(), r1 = read(), l2 = read(), r2 = read();
        l1--;
        l2--;
        q[++cnt] = (zgz) {r1, r2, i, 1};
        if (l1)
            q[++cnt] = (zgz) {l1, r2, i, -1};
        if (l2)
            q[++cnt] = (zgz) {r1, l2, i, -1};
        if (l1 && l2)
            q[++cnt] = (zgz) {l1, l2, i, 1};
    }
    for (int i = 1; i <= cnt; i++)
        if (q[i].l > q[i].r)
            swap(q[i].l, q[i].r);
    sort(q + 1, q + cnt + 1, cmp);
    int l = 0, r = 0;
    for (int i = 1; i <= cnt; i++) {
        int A;
        while (l > q[i].l)
            A = a[l--], sum -= s2[A], s1[A]--;
        while (r > q[i].r)
            A = a[r--], sum -= s1[A], s2[A]--;
        while (l < q[i].l)
            A = a[++l], sum += s2[A], s1[A]++;
        while (r < q[i].r)
            A = a[++r], sum += s1[A], s2[A]++;
        ans[q[i].id] += sum * q[i].ty;
    }
    for (int i = 1; i <= Q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}