//
// Created by 孙启龙 on 2017/4/6.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Trie
{
    int next[1010][4],fail[1010];
    bool end[1010];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 4;i++)
            next[L][i] = -1;
        end[L++] = false;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    int getch(char ch)
    {
        if(ch == 'A')return 0;
        else if(ch == 'C')return 1;
        else if(ch == 'G')return 2;
        else if(ch == 'T')return 3;
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][getch(buf[i])] == -1)
                next[now][getch(buf[i])] = newnode();
            now = next[now][getch(buf[i])];
        }
        end[now] = true;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 4;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            if(end[fail[now]])
                end[now] = true;
            for(int i = 0;i < 4;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int dp[1010][1010];
    int solve(char buf[])
    {
        int len = strlen(buf);
        for(int i = 0;i <= len;i++)
            for(int j = 0;j < L;j++)
                dp[i][j] = INF;
        dp[0][root] = 0;
        for(int i = 0;i < len;i++)
            for(int j = 0;j < L;j++)
                if(dp[i][j] < INF)
                {
                    for(int k = 0;k < 4;k++)
                    {
                        int news = next[j][k];
                        if(end[news])
                            continue;
                        int tmp;
                        if( k == getch(buf[i]))
                            tmp = dp[i][j];
                        else
                            tmp = dp[i][j] + 1;
                        dp[i+1][news] = min(dp[i+1][news],tmp);
                    }
                }
        int ans = INF;
        for(int j = 0;j < L;j++)
            ans = min(ans,dp[len][j]);
        if(ans == INF)ans = -1;
        return ans;
    }

};
char buf[1010];
Trie ac;
int main()
{
    int n;
    int iCase = 0;
    while ( scanf("%d",&n) == 1 && n)
    {
        iCase++;
        ac.init();
        while(n--)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        printf("Case %d: %d\n",iCase,ac.solve(buf));
    }
    return 0;
}