//
// Created by 孙启龙 on 2017/3/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int pa[maxn];

int findset(int x)
{
    return pa[x] == x ? x: pa[x] = findset(pa[x]);
}

int main (void)
{
    int x, y;
    while(scanf("%d", &x) != EOF)
    {
        for(int i = 0; i <= maxn; i++)
            pa[i] = i;
        int refausals = 0;
        while(x != -1)
        {
            scanf("%d", &y);
            x = findset(x); y = findset(y);
            if(x == y)
                ++refausals;
            else
                pa[x] = y;
            scanf("%d", &x);
        }
        printf("%d\n", refausals);
    }
    return 0;
}