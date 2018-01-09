//
// Created by 孙启龙 on 2017/10/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cctype>
#define maxn 1000100
#define type 26

using namespace std;

char str[maxn];
int pos[maxn];

struct Trie{
    int next[maxn][type], fail[maxn], end[maxn], len[maxn];
    int root, L;

    int newnode()
    {
        memset(next[L], 0xff, sizeof(next[L]));
        len[L] = 0;
        end[L] = -1;
        return L++;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char *buf)
    {
        int lens = strlen(buf);
        int now = root;
        for(int i = 0; i < lens; i++)
        {
            int id = buf[i] - 'a';
            if(next[now][id] == -1)
                next[now][id] = newnode();
            now = next[now][id];
        }
        end[now] = 1;
        len[now] = lens;
    }

    void build()
    {
        queue<int>Q;
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
            for(int i = 0; i < type; i++)
            {
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                    fail[next[now][i]] = next[fail[now]][i], Q.push(next[now][i]);
            }
        }
    }

    void work(char *str)
    {
        int id;
        int lens = strlen(str);
        int now = root;
        memset(pos, 0, sizeof(pos));
        for(int i = 0; i < lens; i++)
        {
            if(isupper(str[i]))
                id = str[i] - 'A';
            else if (islower(str[i]))
                id = str[i] - 'a';
            else
                continue;

            now = next[now][id];
            int temp = now;
            while(temp != root)
            {
                if(end[temp] != -1)
                    pos[i + 1] -= 1, pos[i - len[temp] + 1] += 1;
                temp = fail[temp];
            }
        }
        long long cnt = 0;
        for(int i = 0; i < lens; i++)
        {
            cnt += pos[i];
            if(cnt > 0)
                printf("*");
            else
                printf("%c", str[i]);
        }
        printf("\n");
    }
}AC;

int main (void)
{
    int Case, n;
    scanf("%d", &Case);
    while(Case--)
    {
        AC.init();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%s", str), AC.insert(str);
        AC.build();
        getchar();
        gets(str);
        AC.work(str);
    }
    return 0;
}