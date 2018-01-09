//
// Created by 孙启龙 on 2017/10/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>

using namespace std;

int score[110], dp[2][1001][1 << 10];
int n, m, k;

struct Trie{
    int next[1005][4], fail[1005], end[1010];
    int root, L;

    int newnode()
    {
        memset(next[L], 0xff, sizeof(next[L]));
        end[L] = 0;
        return L++;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char buf[], int id)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            int pos = buf[i] - 'A';
            if(next[now][pos] == -1)
                next[now][pos] = newnode();
            now = next[now][pos];
        }
        end[now] |= (1 << id);
    }

    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0; i < 4; i++)
        {
            if(next[root][i] == -1)
                next[root][i] = root;
            else
                fail[next[root][i]] = root, Q.push(next[root][i]);
        }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            end[now] |= end[fail[now]];
            for(int i = 0; i < 4; i++)
            {
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                    fail[next[now][i]] = next[fail[now]][i], Q.push(next[now][i]);
            }
        }
    }

    void solve()
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++)
        {
            memset(dp[(i + 1) % 2], 0, sizeof(dp[(i + 1) % 2]));
            for(int j = 0; j < L; j++)
            {
                for(int k = 0; k < (1 << m); k++)
                {
                    if(dp[i % 2][j][k] == 0)
                        continue;
                    for(int x = 0; x < 4; x++)
                    {
                        int newi = (i + 1) % 2;
                        int newj = next[j][x];
                        int newk = k | end[newj];
                        dp[newi][newj][newk] = dp[i % 2][j][k];
                    }
                }
            }
        }

        int ans = 0xcfffffff;
        for(int j = 0; j < L; j++)
        {
            for(int i = 0; i < (1 << m); i++)
            {
                int cnt = 0;
                if(dp[n % 2][j][i] == 0)
                    continue;
                for(int g = 0; g < m; g++)
                    if(i & (1 << g))
                        cnt += score[g];
                ans = max(ans, cnt);
            }
        }
        if(ans < 0)
            printf("No Rabbit after 2012!\n");
        else
            printf("%d\n", ans);
    }
}AC;

char buf[200];
int main()
{
    while(scanf("%d %d", &m, &n) != EOF)
    {
        AC.init();
        for(int i = 0; i < m; i++)
        {
            scanf("%s", buf);
            int len = strlen(buf);
            for(int pos = 0; pos < len; pos++)
            {
                if(buf[pos] == 'G')
                    buf[pos] = 'B';
                else if (buf[pos] == 'T')
                    buf[pos] = 'D';
            }
            AC.insert(buf, i);
            scanf("%d", &score[i]);
        }
        AC.build();
        AC.solve();
    }
    return 0;
}