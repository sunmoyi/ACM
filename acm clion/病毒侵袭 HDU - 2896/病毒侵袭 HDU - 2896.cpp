//
// Created by 孙启龙 on 2017/4/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn (210 * 500)

using namespace std;

struct Tire{
    int next[maxn][128], fail[maxn], end[maxn];
    int root, L;
    int newnode()
    {
        for(int i = 0; i < 128; i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L - 1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char *s, int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            if(next[now][s[i]] == -1)
                next[now][s[i]] = newnode();
            now = next[now][s[i]];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for (int i = 0; i < 128; i++)
        {
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 128; i++)
            {
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    bool used[510];
    bool query(char *buf, int n, int id)
    {
        int len = strlen(buf);
        int now = root;
        memset(used, false, sizeof(used));
        bool flag = false;
        for(int i = 0; i < len; i++)
        {
            now = next[now][buf[i]];
            int temp = now;
            while(temp != root)
            {
                if(end[temp] != -1)
                {
                    used[end[temp]] = true;
                    flag = true;
                }
                temp = fail[temp];
            }
        }
        if(!flag)
            return false;
        printf("web %d:", id);
        for(int i = 1; i <= n; i++)
            if(used[i])
                printf(" %d", i);
        printf("\n");
        return true;
    }
};

char buf[100010];
Tire ac;

int main (void)
{
    int n, m;
    while(scanf("%d", &n) != EOF)
    {
        ac.init();
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", buf);
            ac.insert(buf, i);
        }
        ac.build();
        int ans = 0;
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%s", buf);
            if(ac.query(buf, n, i))
                ans++;
        }
        printf("total: %d\n", ans);
    }
    return 0;
}