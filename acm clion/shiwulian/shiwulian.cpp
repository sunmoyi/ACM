//
// Created by 孙启龙 on 2017/5/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010

using namespace std;

int father[maxn << 2];
int n, Q, cmd, x, y;

void init()
{
    for(int i = 0; i < (maxn << 2); i++)
        father[i] = i;
}

int find(int x)
{
    int fin = x;
    while(fin != father[fin])
        fin = father[fin];

    while(x != fin)
    {
        int temp = father[x];
        father[x] = fin;
        x = temp;
    }
    return fin;
}

void unoin(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    father[x] = y;
}

int main (void)
{
    scanf("%d %d", &n, &Q);

        init();
        int ans = 0;
        while(Q--)
        {
            scanf("%d %d %d", &cmd, &x, &y);
            if(x > n || y > n || x <= 0 || y <= 0)
                ans++;
            else if(cmd == 1)
            {
                if(find(x) == find(y + maxn) || find(x) == find(y + maxn * 2))
                    ans++;
                else
                    unoin(x, y), unoin(x + maxn, y + maxn), unoin(x + maxn * 2, y + maxn * 2);
            }
            else if (cmd == 2)
            {
                if(find(x) == find(y) || find(x) == find(y + maxn))
                    ans++;
                else
                    unoin(x + maxn, y), unoin(x + maxn * 2, y + maxn), unoin(x, y + maxn * 2);
            }
        }
        printf("%d\n", ans);
    return 0;
}