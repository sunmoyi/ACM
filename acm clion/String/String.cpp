//
// Created by 孙启龙 on 2017/10/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>

#define maxn 2000010
#define maxm 100010

using namespace std;

int pos[maxn];
struct Tire{
    int next[maxn][27], fail[maxn], lenn[maxn], ans[maxn];
    int root, L;

    int insert(char buf[])
    {
        int len = strlen(buf), now = 0;
        for(int i = 0; i < len; i++)
        {
            if(next[now][buf[i] - 'a'] == 0)
            {
                next[now][buf[i] - 'a'] = ++L;
                lenn[L] = i + 1;
            }
            now = next[now][buf[i] - 'a'];
        }
        return now;
    }

    void init()
    {
        memset(next, 0, sizeof(next));
        memset(fail, 0, sizeof(fail));
        memset(lenn, 0, sizeof(lenn));
        memset(ans, 0, sizeof(ans));
        root = L = 0;
    }

    void getfail()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0; i < 27; i++)
        {
            if(next[root][i] == 0)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }

        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < 27; i++)
            {
                if(next[now][i] == 0)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }

    void query(char buf[], int len)
    {
        int now = root;
        for(int i = 0; buf[i]; i++)
        {
            now = next[now][buf[i] - 'a'];
            int temp = now;
            while(temp != root)
            {
                if(lenn[temp] <= len)
                    ans[temp]++;
                temp = fail[temp];
            }
        }
    }
}AC;

char str[maxn];
char *s[maxm];
int len[maxm];
char s1[maxm], s2[maxm];

int main (void)
{
    int T, n, q;
    scanf("%d", &T);
    while(T--)
    {
        AC.init();
        scanf("%d %d", &n, &q);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            s[i] = str + cnt;
            scanf("%s", s[i]);
            len[i] = strlen(s[i]) + 1;
            cnt += len[i];
            strcpy(str + cnt, s[i]);
            str[cnt - 1] = 'z' + 1;
            cnt += len[i];
        }
        for(int i = 0; i < q; i++)
        {
            s1[0] = 'z' + 1;
            scanf("%s%s", s1 + 1, s2);
            strcat(s2, s1);
            pos[i] = AC.insert(s2);
        }
        AC.getfail();
        for(int i = 0; i < n; i++)
            AC.query(s[i], len[i]);
        for(int i = 0; i < q; i++)
            printf("%d\n", AC.ans[pos[i]]);
    }
    return 0;
}