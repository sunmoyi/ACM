//
// Created by 孙启龙 on 2017/10/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>

#define maxn 100010

using namespace std;

char str[maxn];
struct Trie{
    int next[maxn][26], fail[maxn], end[maxn];
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

    void insert(char buf[])
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
        end[now]++;
    }

    void build()
    {
        queue<int>Q;
        fail[root]=root;
        for(int i=0;i<26;i++)
        {
            if(next[root][i]==-1)
                next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty())
        {
            int now=Q.front();
            Q.pop();
            for(int i=0;i<26;i++)
            {
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }

    long long query(char *buf, int len)
    {
        int now = root;
        long long ans = 0;
        for(int i = 0; i < len; i++)
        {
            int id = buf[i] - 'a';
            now = next[now][id];
            int temp = now;
            while(temp != root)
            {
                ans += end[temp];
                temp = fail[temp];
            }
        }
        return ans;
    }
}AC;
int pos[maxn], len[maxn];
char ss[maxn];

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int temp = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", str + temp);
            pos[i] = temp;
            int lens = strlen(str + temp);
            len[i] = lens;
            temp += lens;
        }
        AC.init();
        for(int i = 0; i < m; i++)
        {
            scanf("%s", ss);
            AC.insert(ss);
        }
        AC.build();
        for(int i = 0; i < n; i++)
            printf("%lld\n", AC.query(str + pos[i], len[i]));
    }
    return 0;
}