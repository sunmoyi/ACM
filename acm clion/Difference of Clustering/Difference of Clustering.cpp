//
// Created by 孙启龙 on 2017/7/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 2000010

using namespace std;

int u[maxn], v[maxn], n, a[maxn];
map<int, int>h;
int sz;
bool b[maxn];
int call, call2;

struct link {
    int edge[maxn], next[maxn], pre[maxn], size = 1;
    void mem()
    {
        memset(pre, 0, sizeof(pre));
        memset(edge, 0, sizeof(edge));
        memset(pre, 0, sizeof(pre));
        size = 1;
    }

    void addedge(int u, int v)
    {
        edge[++size] = v;
        next[size] = pre[u];
        pre[u] = size;
    }

    void addedge2(int u, int v)
    {
        addedge(u, v);
        addedge(v, u);
    }

    void dfs(int x)
    {
        b[x] = 1;
        if(x <= n)
            ++call;
        else
            ++call2;
        for(int i = pre[x]; i; i = next[i])
        {
            int v = edge[i];
            if(!b[v])
                dfs(v);
        }
    }
}St;

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        int A = 0, B = 0, C = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            u[i] = x, v[i] = y;
        }
        sz = 0;
        for(int i = 1; i <= n; i++)
            a[++sz] = u[i], a[++sz] = v[i];
        sort(a + 1, a + 1 + sz);
        sz = (int)(unique(a + 1, a + 1 + sz) - (a + 1));
        h.clear();
        for(int i = 1; i <= sz; i++)
            h[a[i]] = i;
        for(int i = 1; i <= n; i++)
            u[i] = h[u[i]], v[i] = h[v[i]];

        St.mem();
        for(int i = 1; i <= n; i++)
            St.addedge2(u[i], v[i] + n);
        for(int i = 1; i <= n * 2; i++)
            b[i] = 0;
        for(int i = 1; i <= n * 2; i++)
        {
            if(!b[i])
            {
                call = call2 = 0;
                St.dfs(i);
                if(call == 1 && call2 == 1)
                    C++;
                else if (call == 1 && call2 > 1)
                    A++;
                else if (call2 == 1 && call > 1)
                    B++;
            }
        }
        printf("Case #%d: %d %d %d\n", Case, A, B, C);
    }
    return 0;
}