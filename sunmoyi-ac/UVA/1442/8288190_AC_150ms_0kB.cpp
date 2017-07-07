//
// Created by 孙启龙 on 2017/2/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int c, f;
}s[maxn];
int n;

void init()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i].f);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i].c);
    int temp = INF;
    for(int i = n - 1; i >= 0; i--)
    {
        temp = min(temp, s[i].c);
        temp = max(temp, s[i].f);
        s[i].c = temp;
    }
}

int solve()
{
    int ans = 0, temp = INF;
    for(int i = 0; i < n; i++)
    {
        temp = min(temp, s[i].c);
        temp = max(temp, s[i].f);
        s[i].c = temp;

        ans += s[i].c - s[i].f;
    }
    return ans;
}

int main (void)
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        init();
        printf("%d\n", solve());
    }
    return 0;
}