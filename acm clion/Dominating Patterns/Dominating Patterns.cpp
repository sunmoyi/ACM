//
// Created by 孙启龙 on 2017/3/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
#define sigma_size 26
#define maxnode 11000
#define maxs 200

using namespace std;

map<string, int>ms;

struct ACAutomata{
    int ch[maxnode][sigma_size];
    int f[maxnode];
    int val[maxnode];
    int last[maxnode];
    int cnt[maxs];
    int sz;

    void init()
    {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(cnt, 0, sizeof(cnt));
        ms.clear();
    }

    int idx(char c)
    {
        return c - 'a';
    }

    void insert(char *s, int v)
    {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
        ms[string(s)] = v;
    }

    void print(int j)
    {
        if(j)
        {
            cnt[val[j]]++;
            print(last[j]);
        }
    }

    int find(char *T)
    {
        int n = strlen(T);
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            int c = idx(T[i]);
            while(j && !ch[j][c])
                j = f[j];
            j = ch[j][c];
            if(val[j])
                print(j);
            else if (last[j])
                print(last[j]);
        }
    }

    void getFail()
    {
        queue<int> q;
        f[0] = 0;
        // 初始化队列
        for(int c = 0; c < sigma_size; c++)
        {
            int u = ch[0][c];
            if(u)
            {
                f[u] = 0;
                q.push(u);
                last[u] = 0;
            }
        }
        // 按BFS顺序计算fail
        while(!q.empty())
        {
            int r = q.front(); q.pop();//r 当前节点的编号
            for(int c = 0; c < sigma_size; c++)
            {
                int u = ch[r][c];//u是当前节点的下一个节点的编号
                if(!u)//如果u不存在
                    continue;
                q.push(u);//将u添加到队列进行失败匹配
                int v = f[r];//v 当前节点的失败匹配节点的编号
                while(v && !ch[v][c])
                    v = f[v];//在当前节点的失配节点中寻找下一个节点的失配节点
                f[u] = ch[v][c];//当前节点的最大失配节点
                last[u] = val[f[u]] ? f[u] : last[f[u]];
                //如果u节点的失配节点是一个单词的结尾 那么就直接使用
            }
        }
    }
};

ACAutomata ac;
char text[1000010], P[maxs][80];
int n, T;

int main (void)
{
    while(scanf("%d", &n) != EOF && n)
    {
        ac.init();
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", P[i]);
            ac.insert(P[i], i);
        }
        ac.getFail();
        scanf("%s", text);
        ac.find(text);
        int best = -1;
        for(int i = 1; i <= n; i++)
            if(ac.cnt[i] > best)
                best = ac.cnt[i];
        printf("%d\n", best);
        for(int i = 1; i <= n; i++)
            if(ac.cnt[ms[string(P[i])]] == best)
                printf("%s\n", P[i]);
    }
}
