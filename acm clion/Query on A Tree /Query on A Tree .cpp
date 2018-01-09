////
//// Created by 孙启龙 on 2017/9/28.
////
//
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include <cstdlib>
//#include <iostream>
//
//#define INF 0x3f3f3f3f
//
//using namespace std;
//
//struct trie{
//    trie *next[2];
//    int cnt;
//    trie() {
//        memset(next, 0, sizeof(next));
//        cnt = 0;
//    }
//};
//trie *root;
//
//void insert(char *s, int x)
//{
//    trie *p = root;
//    for(int i = 31; i >= 0; i--)
//    {
//        int k = s[i] - '0';
//        if(p->next[k] == NULL)
//            p->next[k] = new trie();
//        p = p->next[k];
//    }
//    p->cnt = x;
//}
//
//int query(char *s, int x, int dir)
//{
//    trie *p =  root;
//    for(int i = 31; i >= 0; i--)
//    {
//        int xx = s[i] - '0';
//        xx = xx ^ dir;
//        if(p->next[xx] == NULL)
//            xx ^= 1;
//        p = p->next[xx];
//    }
//    return (p->cnt) ^ x;
//}
//
//void del(trie *p)
//{
//    for(int i = 0; i < 2; i++)
//        if(p->next[i] != NULL)
//            del(p->next[i]);
//    free(p);
//}
//
//void tran(char *a, int x)
//{
//    for(int i = 0; i <= 31; i++)
//        a[i] = '0';
//    a[32] = 0;
//    int i = 0;
//    while(x)
//    {
//        a[i++] = (x % 2) + '0';
//        x /= 2;
//    }
//}
//
//int main (void)
//{
//    int T, n;
//    int sum[50010];
//    scanf("%d", &T);
//    for(int Case = 1; Case <= T; Case++)
//    {
//        root = new trie();
//        scanf("%d", &n);
//        sum[0] = 0;
//        for(int i = 1; i <= n; i++)
//        {
//            int x;
//            scanf("%d", &x);
//            sum[i] = sum[i - 1] ^ x;
//        }
//        char t[33];
//        tran(t, 0);
//        insert(t, 0);
//
//        int maxn = 0, minn = INF;
//        for(int i = 1; i <= n; i++)
//        {
//            tran(t, sum[i]);
//            maxn = max(maxn, query(t, sum[i], 1));
//            minn = min(minn, query(t, sum[i], 0));
//            insert(t, sum[i]);
//
//        }
//        printf("Case %d: %d %d\n", Case, maxn, minn);
//        del(root);
//    }
//    return 0;
//}

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <vector>
#include <cstdlib>

#define maxn 100010

using namespace std;

void tran(char *a, int x)
{
    for(int i = 0; i <= 31; i++)
        a[i] = '0';
    a[32] = '\0';
    int i = 0;
    while(x)
    {
        a[i++] = x % 2 + '0';
        x /= 2;
    }
}

struct trie{
    trie *next[2];
    int cnt;
    trie()
    {
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
};
trie *root[maxn];

void insert(trie *p, int x)
{
    char s[33];
    tran(s, x);
    for(int i = 31; i >= 0; i--)
    {
        int k = s[i] - '0';
        if(p->next[k] == NULL)
            p->next[k] = new trie();
        p = p->next[k];
    }
    p->cnt = x;
}

int query(trie *p, int x, int dir)
{
    char s[33];
    tran(s, x);
    for(int i = 31; i >= 0; i--)
    {
        int x = s[i] - '0';
        x = x ^ dir;
        if(p->next[x] == NULL)
            x ^= 1;
        p = p->next[x];
    }
    return (p->cnt) ^ x;
}

void del(trie *p)
{
    for(int i = 0; i < 2; i++)
        if(p->next[i])
            del(p->next[i]);
    free(p);
}

trie* Merge(trie *a, trie *b)
{
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    a->next[0] = Merge(a->next[0], b->next[0]);
    a->next[1] = Merge(a->next[1], b->next[1]);

    free(b);

    return a;
}

struct Query{
    int id, x;
    Query(int id = 0, int x = 0):id(id), x(x){}
};

int a[maxn];
vector<int>e[maxn];
vector<Query>Q[maxn];
int ans[maxn];

void dfs(int x, int pre)
{
    root[x] = new trie();
    insert(root[x], a[x]);
    for(int i = 0; i < e[x].size(); i++)
    {
        int xx = e[x][i];
        if(xx == pre)
            continue;
        dfs(xx, x);
        Merge(root[x], root[xx]);
    }

    for(int i = 0; i < Q[x].size(); i++)
    {
        ans[Q[x][i].id] = query(root[x], Q[x][i].x, 1);
    }
}

int main (void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2)
    {
        for(int i = 1; i <= n; i++)
        {
            e[i].clear();
            Q[i].clear();
            scanf("%d", &a[i]);
        }
        for(int i = 2; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            e[x].push_back(i);
        }
        for(int i = 1; i <= m; i++)
        {
            int u, x;
            scanf("%d %d", &u, &x);
            Q[u].push_back(Query(i, x));
        }
        dfs(1, -1);
        for(int i = 1; i <= m; i++)
            printf("%d\n", ans[i]);
        del(root[1]);
    }
    return 0;
}
