//
// Created by 孙启龙 on 2017/7/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cctype>

#define maxn 1000100
#define type 26

using namespace std;

char str[maxn];
int pos[maxn];

struct Aho_Corasick{
    int nextt[maxn][type], fail[maxn], end[maxn], l[maxn];
    int root, L;
    int newnode()
    {
        for(int i = 0; i < type; i++)
            nextt[L][i] = -1;
        l[L] = 0;
        end[L++] = -1;
        return L - 1;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char str[])
    {
        int len = (int)strlen(str);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            int id = str[i] - 'a';
            if(nextt[now][id] == -1)
                nextt[now][id] = newnode();
            now = nextt[now][id];
        }
        end[now] = 1;
        l[now] = len;
    }

    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0; i < type; i++)
        {
            if(nextt[root][i] == -1)
                nextt[root][i] = root;
            else
            {
                fail[nextt[root][i]] = root;
                Q.push(nextt[root][i]);
            }
        }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < type; i++)
            {
                if(nextt[now][i] == -1)
                    nextt[now][i] = nextt[fail[now]][i];
                else
                {
                    fail[nextt[now][i]] = nextt[fail[now]][i];
                    Q.push(nextt[now][i]);
                }
            }
        }
    }

    void work(char *str)
    {
        int id;
        int len = (int)strlen(str);
        int now = root;
        memset(pos, 0, sizeof(pos));
        for(int i = 0; i < len; i++)
        {
            if(isupper(str[i]))
                id = str[i] - 'A';
            else if (islower(str[i]))
                id = str[i] - 'a';
            else
                continue;
            now = nextt[now][id];
            int temp = now;
            while(temp != root)
            {
                if(end[temp] != -1)
                {
                    pos[i + 1] -= 1;
                    pos[i - l[temp] + 1] += 1;
                    break;
                }
                temp = fail[temp];
            }
        }
        long long cnt = 0;
        for(int i = 0; i < len; i++)
        {
            cnt += pos[i];
            if(cnt <= 0)
                printf("%c", str[i]);
            else
                printf("*");
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
        {
            scanf("%s", str);
            AC.insert(str);
        }
        AC.build();
        getchar();
        gets(str);
        AC.work(str);
    }
    return 0;
}