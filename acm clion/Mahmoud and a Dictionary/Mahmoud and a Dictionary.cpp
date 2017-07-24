//
// Created by 孙启龙 on 2017/2/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 100010
#define mod 1000000007

using namespace std;

struct node{
    char str[25];
    friend bool operator < (const node&a, const node&b)
    {
        int k = strcmp(a.str, b.str);
        if(k < 0)
            return true;
        else
            return false;
    }
};
map<node, int>mp;
int cnt, d[maxn * 2];
node k1, k2;

int find(int root)
{
    int f = root;
    while(f != d[f])
        f = d[f];

    int temp;
    while(root != d[root])
    {
        temp = d[root];
        d[root] = f;
        root = temp;
    }
    return f;
}

int main (void)
{
    int n, m, q;
    cnt = 0;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", k1.str);
        if(mp[k1] == 0)
            mp[k1] = ++cnt;
    }
    for(int i = 1; i <= 2 * n; i++)
        d[i] = i;
    int p1, p2, t;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%s%s", &t, k1.str, k2.str);
        p1 = mp[k1], p2 = mp[k2];
        int s1 = find(p1), s2 = find(p1 + n);
        int m1 = find(p2), m2 = find(p2 + n);
        if((s1 == m2 && t == 1) || (s1 == m1 && t == 2))
            printf("NO\n");
        else
        {
            printf("YES\n");
            if(t == 1)
            {
                d[s1] = m1;
                d[s2] = m2;
            }
            else
            {
                d[s1] = m2;
                d[s2] = m1;
            }
        }
    }
    for(int i = 1; i <= q; i++)
    {
        scanf("%s%s", k1.str, k2.str);
        p1 = mp[k1], p2 = mp[k2];
        int s1 = find(p1), s2 = find(p1 + n);
        int m1 = find(p2), m2 = find(p2 + n);
        if(s1 == m1)
            printf("1\n");
        else if (s1 == m2)
            printf("2\n");
        else
            printf("3\n");
    }
    return 0;
}