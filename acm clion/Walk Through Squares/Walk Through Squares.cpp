//
// Created by 孙启龙 on 2017/10/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define mod 1000000007
#define maxn 210
#define type 2

using namespace std;

int dp[110][110][210][4];
char buf[110];
int n, m;

struct Trie{
    int next[maxn][type], fail[maxn], end[maxn];
    int root, L;

    int newnode()
    {
        memset(next[L], 0xff, sizeof(next[L]));
        end[L] = 0;
        return L++;
    }

    int ID(char c)
    {
        return (c != 'R');
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char *buf, int id)
    {
        int now = root;
        int len = strlen(buf);
        for(int i = 0; i < len; i++)
        {
            int pos = ID(buf[i]);
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
        for(int i = 0; i < type; i++)
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
            for(int i = 0; i < type; i++)
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
        dp[0][0][0][0] = 1;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                for(int k = 0; k < L; k++)
                    for(int sta = 0; sta < 4; sta++)
                    {
                        if(!dp[i][j][k][sta])
                            continue;
                        int node1 = next[k][0];
                        int node2 = next[k][1];
                        int sta1 = sta | end[node1];
                        int sta2 = sta | end[node2];
                        (dp[i][j + 1][node1][sta1] += dp[i][j][k][sta]) %= mod;
                        (dp[i + 1][j][node2][sta2] += dp[i][j][k][sta]) %= mod;
                    }
        int ans = 0;
        for(int i = 0; i < L; i++)
            (ans += dp[n][m][i][3]) %= mod;
        return ans;
    }
}AC;

int main (void)
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        scanf("%d %d", &m, &n);
        AC.init();
        scanf("%s", buf);
        AC.insert(buf, 0);
        scanf("%s", buf);
        AC.insert(buf, 1);
        AC.build();
        printf("%d\n", AC.solve());
    }
    return 0;
}