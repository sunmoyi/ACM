//
// Created by 孙启龙 on 2017/3/31.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#define sigma_size 26
#define maxnode 10010

using namespace std;

void process_match(int pos, int v);

struct ACAutoMata{
    int ch[maxnode][sigma_size];
    int f[maxnode];
    int val[maxnode];
    int last[maxnode];
    int sz;

    void init()
    {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }

    // 字符c的编号
    int idx(char c)
    {
        return c-'a';
    }

    // 插入字符串。v必须非0
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
    }

    // 递归打印以结点j结尾的所有字符串
    void report(int pos, int j)
    {
        if(j)900
        {
            process_match(pos, val[j]);
            report(pos, last[j]);
        }
    }

    // 在T中找模板
    int find(char* T)
    {
        int n = strlen(T);
        int j = 0; // 当前结点编号，初始为根结点
        for(int i = 0; i < n; i++)
        { // 文本串当前指针
            int c = idx(T[i]);
            while(j && !ch[j][c])
                j = f[j]; // 顺着细边走，直到可以匹配
            j = ch[j][c];
            if(val[j])
                report(i, j);
            else if(last[j])
                report(i, last[j]); // 找到了！
        }
    }

    // 计算fail函数
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
            int r = q.front(); q.pop();
            for(int c = 0; c < sigma_size; c++)
            {
                int u = ch[r][c];
                if(!u)
                    continue;
                q.push(u);
                int v = f[r];
                while(v && !ch[v][c])
                    v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
};

ACAutoMata ac;

#define maxn 1010
#define maxm 1010
#define maxx 110
#define maxy 110

char text[maxn][maxm], P[maxx][maxy];
int repr[maxx];
int nextt[maxx];
int len[maxx];
int tr;
int cnt[maxn][maxm];

void process_match(int pos, int v)
{
    int pr = repr[v - 1];
    int c = pos - len[pr] + 1;
    while(pr >= 0)
    {
        if(tr >= pr)
            cnt[tr - pr][c]++;
        pr = nextt[pr];
    }
}

int main (void)
{
    int T, n, m, x, y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%s", text[i]);

        scanf("%d %d", &x, &y);
        ac.init();
        for(int i = 0; i < x; i++)
        {
            scanf("%s", P[i]);
            len[i] = strlen(P[i]);
            repr[i] = i;
            nextt[i] = -1;
            for(int j = 0; j < i; j++)
            {
                if(strcmp(P[i], P[j]) == 0)
                {
                    repr[i] = j;
                    nextt[i] = nextt[j];
                    nextt[j] = i;
                    break;
                }
            }
            if(repr[i] == i)
                ac.insert(P[i], i + 1);
        }
        ac.getFail();

        memset(cnt, 0, sizeof(cnt));
        for(tr = 0; tr < n; tr++)
            ac.find(text[tr]);

        int ans = 0;
        for(int i = 0; i < n - x + 1; i++)
            for(int j = 0; j < m - y + 1; j++)
                if(cnt[i][j] == x)
                    ans++;
        printf("%d\n", ans);
    }
    return 0;
}