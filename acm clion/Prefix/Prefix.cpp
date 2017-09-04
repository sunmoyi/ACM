//
// Created by 孙启龙 on 2017/8/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

int root[maxn], cnt, n;
struct node{
    int l, r, sum;
}tree[maxn * 40];

void update(int l, int r, int x, int &y, int pos)       //(l,r,root[x],root[x+1],pos)
{
    tree[++cnt] = tree[x], tree[cnt].sum++, y = cnt;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    if (mid >= pos)
        update(l, mid, tree[x].l, tree[y].l, pos);
    else
        update(mid + 1, r, tree[x].r, tree[y].r, pos);
}

int query(int l, int r, int x, int y, int k) {
    if (l == r)
        return tree[y].sum - tree[x].sum;
    int mid = (l + r) / 2;
    if (k > mid)
        return tree[tree[y].l].sum - tree[tree[x].l].sum + query(mid + 1, r, tree[x].r, tree[y].r, k);
    else
        return query(l, mid, tree[x].l, tree[y].l, k);
}

char s[maxn];

struct TIRE{
    int cnt, pos;
    struct Tire{
        int p[26], s;
    }tr[maxn];

    void init()
    {
        pos = 1;
        cnt = 0;
        memset(tr[0].p, 0, sizeof(tr[0].p));
        tr[0].s = 0;
    }

    void insert(int time)
    {
        int len = strlen(s), t = 0;
        int t1 = root[time - 1], t2;

        for (int x = 0; x < len; x++)
        {
            if (tr[t].p[s[x] - 'a'])
            {
                t = tr[t].p[s[x] - 'a'];
                update(1, n, t1, t2, tr[t].s + 1);
                t1 = t2;
                tr[t].s = time;
            }
            else
            {
                t = tr[t].p[s[x] - 'a'] = ++cnt;
                update(1, n, t1, t2, 1);
                t1 = t2;
                tr[t].s = time;
                memset(tr[t].p, 0, sizeof(tr[t].p));
            }
        }
        root[time] = t2;
    }
}tire;

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        tire.init();
        cnt = 0;
        root[0] = 0;
        tree[0].l = tree[0].r = tree[0].sum = 0;
        for(int i = 1; i <= n; i++)
            scanf("%s", s), tire.insert(i);
        s[0] = 0;
        tire.insert(n + 1);
        int z = 0, l, r;
        int m;
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &l, &r);
            l = (z + l) % n + 1;
            r = (z + r) % n + 1;
            if(l > r)
                swap(l, r);

            z = query(1, n, root[l - 1], root[r], l);
            printf("%d\n", z);
        }
    }
    return 0;
}