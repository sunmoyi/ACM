//
// Created by 孙启龙 on 2017/3/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 150010

using namespace std;

int father[maxn];
int ans, n, m;

void init()
{
    ans = 0;
    memset(father, -1, sizeof(father));
}

int find(int x)
{
    if(father[x] == -1)
        return x;
    return father[x] = find(father[x]);
}

void unoin(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
    {
        father[fx] = fy;
    }
}

int main (void)
{
        scanf("%d %d", &n, &m);

        init();
        int a, b, c;
        while(m--)
        {
            scanf("%d %d %d", &a, &b, &c);
            if(b <= 0 || c <= 0 || b > n || c > n)
                ans++;
            else
            {
                if(a == 1)
                {
                    if(find(b) == find(c + n) ||find(b) == find(c + 2 * n))
                        ans++;
                    else
                    {
                        unoin(b, c);
                        unoin(b + n, c + n);
                        unoin(b + 2 * n, c + 2 * n);
                    }
                }
                else
                {
                    if(find(b) == find(c) || find(b) == find(c + 2 * n))
                        ans++;
                    else
                    {
                        unoin(b, c + n);
                        unoin(b + n, c + 2 * n);
                        unoin(b + 2 * n, c);
                    }
                }
            }
        }
        printf("%d\n", ans);

    return 0;
}