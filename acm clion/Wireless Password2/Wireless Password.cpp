//
// Created by 孙启龙 on 2017/10/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>

#define mod 20090717

using namespace std;

int n, m, k;
int dp[30][110][1 << 10];
int num[5000];

struct Trie{
    int next[110][26], fail[110], end[110];
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

    void insert(char *buf, int id)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            int id = buf[i] - 'a';
            if(next[now][id] == -1)
                next[now][id] = newnode();
            now = next[now][id];
        }
        end[now] |= (1 << id);
    }

    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0; i < 26; i++)
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
            for(int i = 0; i < 26; i++)
            {
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                    fail[next[now][i]] = next[fail[now]][i], Q.push(next[now][i]);
            }
        }
    }

    int solve()
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < L; j++)
                for(int p = 0; p < (1 << m); p++)
                    if(dp[i][j][p] > 0)
                    {
                        for(int x = 0; x < 26; x++)
                        {
                            int ii = i + 1;
                            int jj = next[j][x];
                            int pp = p | end[jj];
                            dp[ii][jj][pp] += dp[i][j][p];
                            dp[ii][jj][pp] %= mod;
                        }
                    }
        int ans = 0;
        for(int p = 0; p < (1 << m); p++)
        {
            if(num[p] < k)
                continue;
            for(int i = 0; i < L; i++)
                ans = (ans + dp[n][i][p]) % mod;
        }
        return ans;
    }
}ac;

char buf[20];

int main(void)
{
    for(int i = 0; i < (1 << 10); i++)
    {
        num[i] = 0;
        for(int j = 0; j < 10; j++)
            if(i & (1 << j))
                num[i]++;
    }
    while(scanf("%d %d %d", &n, &m, &k) != EOF && (n + m + k))
    {
        ac.init();
        for(int i = 0; i < m; i++)
            scanf("%s", buf), ac.insert(buf, i);
        ac.build();
        printf("%d\n", ac.solve());
    }
    return 0;
}