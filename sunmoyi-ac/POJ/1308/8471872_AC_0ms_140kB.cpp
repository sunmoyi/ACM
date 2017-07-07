//
// Created by 孙启龙 on 2017/3/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int father[maxn], maxx, x, y;
bool used[maxn], is_tree;

void init()
{
    for(int i = 0; i < maxn; i++)
        father[i] = i;
}

int find(int x)
{
    if(x == father[x])
        return x;
    return father[x] = find(father[x]);
}

void unoin(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)
    {
        is_tree = false;
        return;
    }
    else
    {
        father[x] = y;
        return;
    }
}

bool single_root(int n)
{
    int i = 1;
    while(i <= n && !used[i])
        i++;
    int root = find(i);
    while(i <= n)
    {
        if(used[i] && find(i) != root)
            return false;
        i++;
    }
    return true;
}

int main (void)
{
    int Case = 1;
    is_tree = true;
    maxx = 0;
    memset(used, false, sizeof(used));
    init();
    while(scanf("%d %d", &x, &y) != EOF)
    {
        if(x < 0 || y < 0)
            break;
        if(x == 0 || y == 0)
        {
            if(is_tree && single_root(maxx))
                printf("Case %d is a tree.\n", Case++);
            else
                printf("Case %d is not a tree.\n", Case++);
            is_tree = true;
            maxx = 0;
            memset(used, 0, sizeof(used));
            init();
            continue;
        }
        if(!is_tree)
            continue;

        maxx = max(maxx, max(x, y));
        used[x] = used[y] = true;
        unoin(x, y);
    }
    return 0;
}