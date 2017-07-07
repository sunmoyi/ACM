//
// Created by 孙启龙 on 2016/11/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define maxnode 100010

using namespace std;

int n;
int s[maxn];
int sz;
int ch[maxnode][2];
int val[maxnode];

void init()
{
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
}

void update(int v, int d)
{
    int u = 0;
    for(int i = 30; i >= 0; i--)
    {
        int c = (v >> i) & 1;
        if(!ch[u][c])
        {
            memset(ch[sz], 0, sizeof(ch[sz]));
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
        val[u] += d;
    }
}

int match(int v)
{
    int ans = 0, u = 0;
    for(int i = 30; i >= 0; i--)
    {
        int c = (v >> i) & 1;
        if(ch[u][c ^ 1] && val[ch[u][c ^ 1]])
        {
            ans |= (1 << i);
            u = ch[u][c ^ 1];
        }
        else
            u = ch[u][c];
    }
    return ans;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &s[i]);
            update(s[i], 1);
        }

        int ans = (s[1] + s[2]) ^ s[3];
        for(int i = 1; i < n; i++)
        {
            update(s[i], -1);
            for(int j = i + 1; j <= n; j++)
            {
                update(s[j], -1);
                int t = match(s[i] + s[j]);
                ans = max(ans, t);
                update(s[j], 1);
            }
            update(s[i], 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}