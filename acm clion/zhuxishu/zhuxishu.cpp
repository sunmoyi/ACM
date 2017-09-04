//
// Created by 孙启龙 on 2017/8/14.
//

#include <stdio.h>
#include <stdlib.h>

#define S struct Seg
#define mid (l+r>>1)
char *sp, str[1000000], *p = str;
int n, m, a[20001][2], s, ra[20001], K, Y = 1, I, b[20000], v[10001] = {-2, -2};
struct Seg {
    Seg *c[2];
    int s;
} *R[10001], st[2500000], *stp = st, *T[10001];

int getint() {
    int re = 0;
    while (*p < '0' || *p > '9')
        p++;
    while (*p >= '0' && *p <= '9')
        re = re * 10 + *p++ - 48;
    return re;
}

int cmp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

Seg *Build(l, r) {
    S *node = stp++;
    if (l + 1 != r)
        node->c[0] = Build(l, mid), node->c[1] = Build(mid, r);
    return node;
}

S *SegInsert(x, l, r)

S *x;
int l, r;
{
S *node = stp++;
node->
s = x->s + Y;
if(l+1!=r){
if(I<mid)node->c[1]=x->c[1],node->c[0]=
SegInsert(x
->c[0],l,mid);
else node->c[0]=x->c[0],node->c[1]=
SegInsert(x
->c[1],mid,r);
}return
node;
}

void BitInsert(x) {
    for (; x <= n; x += x & -x)
        R[x] = SegInsert(R[x], 0, K);
}

void Init(x) {
    for (; x; x -= x & -x)
        if (v[x] != m)
            v[x] = m, T[x] = R[x];
        else
            v[x] = -2;
}

void Turn(int x, _Bool c) {
    for (; x; x -= x & -x)
        if (v[x] == m)
            T[x] = T[x]->c[c];
}

int BitQuery(x) {
    int ans = 0;
    for (; x; x -= x & -x)
        if (v[x] == m)
            ans += T[x]->c[0]->s;
    return ans;
}

void print(x) {
    char out[10], *buf = out;
    if (!x)
        *sp++ = '0';
    else {
        while (x)
            *buf++ = x % 10 + 48, x /= 10;
        while (buf-- != out)
            *sp++ = *buf;
    }
    *sp++ = '\n';
}

main() {
    int i, j, k, re, l, r;
    fread(p, 1, 1000000, stdin);
    for (s = n = i = getint(), m = getint(); i--; a[i][1] = n - i - 1)
        a[i][0] = getint();
    for (sp = p; *p;)
        if (*p++ == 'C')
            getint(), a[s][1] = s, a[s++][0] = getint();
    a[a[s][1] = s][0] = ra[s] = -1;
    for (qsort(a, s, 8, cmp); s--; b[ra[a[s][1]] = ra[a[s + 1][1]] + (a[s][0] != a[s + 1][0])] = a[s][0]);
    for (R[i = 1] = Build(0, K = ra[a[0][1]] + 1); i++ != n; v[i] = -2)
        R[i] = R[1];
    for (s = n, p = sp, sp = str, i = -1; ++i != n; BitInsert(i + 1))
        I = ra[i];
    while (m--) {
        while (*p != 'Q' && *p != 'C')
            p++;
        if (*p == 'Q') {
            i = getint() - 1;
            j = getint();
            k = getint();
            Init(i);
            Init(j);
            l = 0;
            r = K;
            while (l + 1 != r)
                if ((re = BitQuery(j) - BitQuery(i)) >= k)
                    Turn(i, 0), Turn(j, 0), r = mid;
                else
                    Turn(i, 1), Turn(j, 1), k -= re, l = mid;
            print(b[l]);
        } else if (ra[(i = getint()) - 1] != ra[s++]) {
            I = ra[i - 1];
            Y = -1;
            BitInsert(i);
            I = ra[i - 1] = ra[s - 1];
            Y = 1;
            BitInsert(i);
        }
    }
    fwrite(str, 1, sp - str, stdout);
    return 0;
}