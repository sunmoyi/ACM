//
// Created by 孙启龙 on 2017/10/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 100100

using namespace std;

struct Trie{
    int len[maxn], next[maxn][26], fail[maxn], flag[maxn];
    int root, L;

    void init()
    {
        L = 0;
        root = newnode();
        len[root] = 0;
    }

    int newnode()
    {
        for(int i = 0; i < 26; i++)
            next[L][i] = -1;
        flag[L] = 0;
        return L++;
    }

    void insert(char s[])
    {
        int now = root;
        int lens = strlen(s);
        for(int i = 0; i < lens; i++)
        {
            int id = s[i] - 'a';
            if(next[now][id] == -1)
                next[now][id] = newnode();
            len[next[now][id]] = len[now] + 1;
            now = next[now][id];
        }
    }

    void build()
    {
        queue<int>q;
        fail[root] = root;
        for (int i = 0; i < 26; ++i)
        {
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i] ] = root;
                q.push(next[root][i]);
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i)
            {
                if (next[u][i] == -1)
                {
                    next[u][i] = next[fail[u] ][i];
                }
                else
                {
                    fail[next[u][i] ] = next[fail[u] ][i];
                    q.push(next[u][i]);
                }
            }
        }
    }

    void update(char s[], int vis)
    {
        int lens = strlen(s);
        int now = root;
        for(int i = 0; i < lens; i++)
        {
            int id = s[i] - 'a';
            now = next[now][id];
            int temp = now;
            while(temp != root)
            {
                flag[temp] = vis;
                temp = fail[temp];
            }
        }
    }

    int query(char s[], int vis)
    {
        int lens = strlen(s);
        int now = root;
        int ans = 0;
        for(int i = 0; i < lens; i++)
        {
            int id = s[i] - 'a';
            now = next[now][id];
            int temp = now;
            while(temp != root)
            {
                if(flag[temp] == vis)
                    ans = max(ans, len[temp]);
                temp = fail[temp];
            }
        }
        return ans;
    }
}AC;

char s[maxn];
int d;
int pos[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        d = 0;
        AC.init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            pos[i] = d;
            scanf("%s", s + d);
            AC.insert(s + d);
            int len = strlen(s + d);
            d += len + 1;
        }
        AC.build();
        int q;
        scanf("%d", &q);
        int vis = 1;
        while(q--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;
            AC.update(s + pos[x], vis);
            int ans = AC.query(s + pos[y], vis);
            ++vis;
            printf("%d\n", ans);
        }
    }
    return 0;
}