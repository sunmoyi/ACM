//
// Created by 孙启龙 on 2017/4/6.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int a[110];
int dp[55][1110];
char str[55][1110][55];

bool cmp(char s1[],char s2[])
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    if(len1 != len2)return len1 < len2;
    else return strcmp(s1,s2) < 0;
}

const int INF=0x3f3f3f3f;
struct Trie
{
    int next[1110][26],fail[1110],end[1110];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[],int id)
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
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
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void solve(int n)
    {
        for(int i = 0; i <= n; i++)
            for(int j = 0; j < L; j++)
                dp[i][j] = -INF;
        dp[0][0] = 0;
        strcpy(str[0][0], "");
        char ans[55];
        strcpy(ans, "");
        int maxx = 0;
        char temp[55];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < L; j++)
            {
                if(dp[i][j] >= 0)
                {
                    strcpy(temp, str[i][j]);
                    int len = strlen(temp);
                    for(int k = 0; k < 26; k++)
                    {
                        int net = next[j][k];
                        temp[len] = 'a' + k;
                        temp[len + 1] = 0;
                        int tt = dp[i][j];
//                        int aa = net;
//                        while(aa != root)
//                        {
//                            if(end[aa] != -1)
//                                tt += a[end[aa]];
//                            aa = fail[aa];
//                        }
                        if(end[net] != -1)
                            tt += a[end[net]];

                        if(dp[i + 1][net] < tt || (dp[i + 1][net] == tt && cmp(temp, str[i + 1][net])))
                        {
                            dp[i + 1][net] = tt;
                            strcpy(str[i + 1][net], temp);
                            if(tt > maxx || (tt == maxx && cmp(temp, ans)))
                            {
                                maxx = tt;
                                strcpy(ans, temp);
                            }
                        }
                    }
                }
            }
//        printf("%d\n", maxx);
        printf("%s\n", ans);
    }
};

char buf[60];
Trie ac;
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        ac.init();
        for(int i = 0;i < m;i++)
        {
            scanf("%s",buf);
            ac.insert(buf,i);
        }
        for(int i = 0;i < m;i++)
            scanf("%d",&a[i]);
        ac.build();
        ac.solve(n);
    }
    return 0;
}
