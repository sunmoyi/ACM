//
// Created by 孙启龙 on 2017/3/10.
//
//interval-tree
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define maxn 1000010
//
//using namespace std;
//
//struct node{
//    int l, r;
//    long long sum, add;
//}trees[maxn << 2];
//
//void pushup(int root)
//{
//    trees[root].sum = trees[root << 1].sum + trees[root << 1 | 1].sum;
//}
//
//void pushdown(int root, int m)
//{
//    if(trees[root].add)
//    {
//        trees[root << 1].add += trees[root].add;
//        trees[root << 1 | 1].add += trees[root].add;
//        trees[root << 1].sum += trees[root].add * (m - (m >> 1));
//        trees[root << 1 | 1].sum += trees[root].add * (m >> 1);
//        trees[root].add = 0;
//    }
//}
//
//void build(int l, int r, int root)
//{
//    trees[root].l = l, trees[root].r = r;
//    trees[root].add = 0;
//    if(l == r)
//    {
//        scanf("%lld", &trees[root].sum);
//        return ;
//    }
//
//    int mid = (trees[root].l + trees[root].r) >> 1;
//    build(l, mid, root << 1);
//    build(mid + 1, r, root << 1 | 1);
//    pushup(root);
//}
//
//void update(int c, int l, int r, int root)
//{
//    if(trees[root].l == l && trees[root].r == r)
//    {
//        trees[root].add += c;
//        trees[root].sum += (long long)c * (r - l + 1);
//        return;
//    }
//    if(trees[root].l == trees[root].r)
//        return;
//
//    pushdown(root, trees[root].r - trees[root].l + 1);
//
//    int mid = (trees[root].l + trees[root].r) >> 1;
//    if(r <= mid)
//        update(c, l, r, root << 1);
//    else if(l > mid)
//        update(c, l, r, root << 1 | 1);
//    else
//    {
//        update(c, l, mid, root << 1);
//        update(c, mid + 1, r, root << 1 | 1);
//    }
//    pushup(root);
//}
//
//long long query(int l, int r, int root)
//{
//    if(l == trees[root].l && r == trees[root].r)
//        return trees[root].sum;
//
//    pushdown(root, trees[root].r - trees[root].l + 1);
//
//    int mid = (trees[root].l + trees[root].r) >> 1;
//    long long res = 0;
//    if(r <= mid)
//        res +=query(l, r, root << 1);
//    else if (l > mid)
//        res += query(l, r, root << 1 | 1);
//    else
//    {
//        res += query(l, mid, root << 1);
//        res += query(mid + 1, r, root << 1 | 1);
//    }
//    return res;
//}
//
//int main (void)
//{
//    int n, m;
//    char ch[2];
//    while(scanf("%d %d", &n, &m) != EOF)
//    {
//        build(1, n, 1);
//        while(m--)
//        {
//            scanf("%s", ch);
//            int a, b, c;
//            if(ch[0] == 'Q')
//            {
//                scanf("%d %d", &a, &b);
//                printf("%lld\n", query(a, b, 1));
//            }
//            else
//            {
//                scanf("%d %d %d", &a, &b, &c);
//                update(c, a, b, 1);
//            }
//        }
//    }
//    return 0;
//}

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

long long n, q;
long long sum[maxn], c1[maxn], c2[maxn];

long long lowbit(long long x)
{
    return x & (-x);
}

void update(long long x, long long d, long long c[])
{
    for(long long i = x; i <= n; i += lowbit(i))
        c[i] += d;
}

long long query(long long x, long long c[])
{
    long long sum = 0;
    for(long long i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

int main(void)
{
    char op[3];
    long long x, y, d;
    while(scanf("%lld %lld", &n, &q) != EOF)
    {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for(int i = 1; i <= n; i++)
            scanf("%lld", &sum[i]), sum[i] += sum[i - 1];
        for(int i = 0; i < q; i++)
        {
            scanf("%s", op);
            if(op[0] == 'C')
            {
                scanf("%lld %lld %lld", &x, &y, &d);
                update(x, d, c1);
                update(y + 1, -d, c1);
                update(x, x * d, c2);
                update(y + 1, -(y + 1) * d, c2);
            }
            else
            {
                scanf("%lld %lld", &x, &y);
                long long ans1 = sum[y] + (y + 1) * query(y, c1) - query(y, c2);
                long long ans2 = sum[x - 1] + x * query(x - 1, c1) - query(x - 1, c2);
                printf("%lld\n", ans1 - ans2);
            }
        }
    }
    return 0;
}
































