//
// Created by 孙启龙 on 2017/5/19.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 7010

using namespace std;

struct node{
    int pos, who, final;
    node(int pos = 0, int who = 0, int final = 0): pos(pos), who(who), final(final){}
};
int n, k[3], s[3][maxn], num[maxn][3], f[maxn][3];
bool vis[maxn][3];

int main (void)
{
    scanf("%d", &n);
    scanf("%d", &k[1]);
    for(int i = 1; i <= k[1]; i++)
        scanf("%d", &s[1][i]);
    scanf("%d", &k[2]);
    for(int i = 1; i <= k[2]; i++)
        scanf("%d", &s[2][i]);
    f[0][1] = f[0][2] = 2;



    queue<node>Q;
    //1 win  2 lose  0 loop
    Q.push(node(0, 1, 2));vis[0][1] = true;
    Q.push(node(0, 2, 2));vis[0][2] = true;
    while(!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        if(now.final == 2)
        {
            int next = 3 - now.who;
            for(int i = 1; i <= k[next]; i++)
            {
                int pos = (now.pos - s[next][i] + n) % n;
                if(!vis[pos][next])
                {
                    f[pos][next] = 1;
                    Q.push(node(pos, next, 1));
                    vis[pos][next] = true;
                }
            }
        }
        else
        {
            int next = 3 - now.who;
            for(int i = 1; i <= k[next]; i++)
            {
                int pos = (now.pos - s[next][i] + n) % n;
                num[pos][next]++;
                if(!vis[pos][next] && num[pos][next] == k[next])
                {
                    f[pos][next] = 2;
                    Q.push(node(pos, next, 2));
                    vis[pos][next] = true;
                }
            }
        }
    }

    for(int i = 1; i < n; i++)
    {
        if(f[i][1] == 1)
            printf("Win ");
        else if (f[i][1] == 2)
            printf("Lose ");
        else
            printf("Loop ");
    }
    printf("\n");
    for(int i = 1; i < n; i++)
    {
        if(f[i][2] == 1)
            printf("Win ");
        else if (f[i][2] == 2)
            printf("Lose ");
        else
            printf("Loop ");
    }
    return 0;
}