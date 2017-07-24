//
// Created by 孙启龙 on 2017/5/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 55555

using namespace std;

struct node{
    int w, fa, lch, rch;
    char s[110];
    bool operator < (const node&a)const {
        return strcmp(s, a.s) <= 0;
    }
}p[maxn];
int n;

void insert(int i)
{
    int j = i - 1;
    while(p[j].w < p[i].w)
        j = p[j].fa;
    p[i].lch = p[j].rch;
    p[j].rch = i;
    p[i].fa = j;
}

void solve(int root)
{
    if(root == 0)
        return;
    printf("(");
    solve(p[root].lch);
    printf("%s/%d", p[root].s, p[root].w);
    solve(p[root].rch);
    printf(")");
}

int main(void)
{
    char s[111], temp[111];
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", s);
            int j;
            for(j = 0; s[j]; j++)
                if(s[j] == '/')
                    break;
                else
                    temp[j] = s[j];
            temp[j++] = '\0';
            int num = 0;
            for(; s[j]; j++)
                num = num * 10 + s[j] - '0';
            strcpy(p[i].s, temp);
            p[i].w = num;
            p[i].lch = p[i].rch = 0;
            p[i].fa = 0;
        }
        sort(p + 1, p + n + 1);
        p[0].w = 0x3f3f3f3f;
        p[0].lch = p[0].rch = p[0].fa = 0;
        for(int i = 1; i <= n; i++)
            insert(i);
        solve(p[0].rch);
        printf("\n");
    }
    return 0;
}