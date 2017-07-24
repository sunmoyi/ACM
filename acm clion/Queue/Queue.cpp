//
// Created by 孙启龙 on 2017/7/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

struct Peo{
    int h, num;
}p[maxn];
int n, s[maxn << 2], res[maxn];

bool cmp(Peo a, Peo b)
{
    return a.h < b.h;
}

void pushup(int root)
{
    s[root] = s[root << 1] + s[root << 1 | 1];
}

void build(int root, int l, int r)
{
    if(l == r)
    {
        s[root] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    pushup(root);
}

void modify(int root, int l, int r, int pos, int val)
{
    if(l == r)
    {
        res[l] = val;
        s[root] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= s[root << 1])
        modify(root << 1, l, mid, pos , val);
    else
        modify(root << 1 | 1, mid + 1, r, pos - s[root << 1], val);
    pushup(root);
}

int main (void)
{
    int t, Case = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        build(1, 1, n);
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &p[i].h, &p[i].num);

        sort(p + 1, p + n + 1, cmp);

        int flag = 0;
        for(int i = 1; i <= n; i++)
        {
            int m = n - i;
            int temp = m - p[i].num;
            if(temp < 0)
            {
                flag = 1;
                break;
            }
            if(p[i].num < temp)
                modify(1, 1, n, p[i].num + 1, p[i].h);
            else
                modify(1, 1, n, temp + 1, p[i].h);
        }
        printf("Case #%d: ", Case++);
        if(flag)
        {
            printf("impossible\n");
            continue;
        }
        printf("%d", res[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", res[i]);
        printf("\n");
    }
    return 0;
}