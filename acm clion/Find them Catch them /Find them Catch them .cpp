//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000 * 2 + 16

using namespace std;

int parent[maxn];
int T, N, M;
char cmd;
int x, y;

void init(const int& n)
{
    for(int i = 0; i < n; i++)
        parent[i] = i;
}

int find(int x)
{
    int xx = x;
    while(xx != parent[xx])
        xx = parent[xx];

    int temp;
    while(x != xx)
    {
        temp = parent[x];
        parent[x] = xx;
        x = temp;
    }
    return xx;
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    parent[x] = y;
}

bool same(const int& x, const int& y)
{
    return find(x) == find(y);
}

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &N, &M);
        init(N * 2 + 1);
        getchar();
        while(M--)
        {
            scanf("%c%d%d%*c", &cmd, &x, &y);
            if(cmd == 'A')
            {
                if(same(x, y))
                    printf("In the same gang.\n");
                else if (same(x + N, y))
                    printf("In different gangs.\n");
                else
                    printf("Not sure yet.\n");
            }
            else
            {
                unite(x + N, y);
                unite(x, y + N);
            }
        }
    }
    return 0;
}