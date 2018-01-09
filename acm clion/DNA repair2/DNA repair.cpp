//
// Created by 孙启龙 on 2017/10/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f
#define maxn 1010

using namespace std;

struct Trie{
    int next[maxn][4], fail[maxn];
    bool end[maxn];
    int root, L;

    int newnode()
    {
        memset(next[L], 0xff, sizeof(next[L]));
        end[L] = false;
        return L++;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    int getint(char ch)
    {
        switch (ch)
        {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
        }
    }

    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            int id = getint(buf[i]);
            if(next[now][id] == -1)
                next[now][id] = newnode();
            now = next[now][id];
        }
        end[now] = true;
    }

    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 4; i++) {
            if (next[root][i] == -1)
                next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }

        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            if (end[fail[now]]) end[now] = 1; //notice
            for (int i = 0; i < 4; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }

    int dp[maxn][maxn];
    int solve(char buf[])
    {
        int len = strlen(buf);
        memset(dp, 0x3f, sizeof(dp));

        dp[0][root] = 0;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < L; j++)
            {
                if(dp[i][j] == INF)
                    continue;
                for(int k = 0; k < 4; k++)
                {
                    int now = next[j][k];
                    if(end[now])
                        continue;
                    if(k == getint(buf[i]))
                        dp[i + 1][now] = min(dp[i + 1][now], dp[i][j]);
                    else
                        dp[i + 1][now] = min(dp[i + 1][now], dp[i][j] + 1);
                }
            }
        }
        int ans = INF;
        for(int j = 0; j < L; j++)
            ans = min(ans, dp[len][j]);
        if(ans == INF)
            return -1;
        return ans;
    }
}AC;
char buf[maxn];

int main (void)
{
    int n, Case = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        AC.init();
        while(n--)
        {
            scanf("%s", buf);
            AC.insert(buf);
        }
        AC.build();
        scanf("%s", buf);
        printf("Case %d: %d\n", Case++, AC.solve(buf));
    }
    return 0;
}