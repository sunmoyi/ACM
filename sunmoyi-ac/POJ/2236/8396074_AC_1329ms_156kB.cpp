//
// Created by 孙启龙 on 2017/3/11.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1010

using namespace std;

int f[maxn], x[maxn], y[maxn];
int d, n, i, r, r1, r2, k1, k2;
bool vis[maxn];
vector<int>way;
char ch;

bool dis(int a, int b)
{
    int q = x[a] - x[b];
    int w = y[a] - y[b];
    if(q * q + w * w <= d * d)
        return true;
    else
        return false;
}

int find(int x)
{
    if(x == f[x])
        return x;
    return f[x] = find(f[x]);
}

int main (void)
{
    while(scanf("%d %d", &n, &d) != EOF)
    {
        way.clear();
        for(int i = 1; i <= n; i++)
        {
            f[i] = i;
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &x[i], &y[i]);
        getchar();
        while(scanf("%c", &ch) != EOF)
        {
            if(ch == 'O')
            {
                scanf("%d", &r);
                vis[r] = true;
                for(int i = 0; i < way.size(); i++)
                {
                    int ss = way[i];
                    if(ss != r && vis[ss] && dis(ss, r))
                    {
                        k1 = find(ss);
                        k2 = find(r);
                        f[k2] = k1;
                    }
                }
                way.push_back(r);
            }
            else if (ch == 'S')
            {
                scanf("%d %d", &r, &r1);
                k1 = find(r);
                k2 = find(r1);
                if(k1 == k2)
                    printf("SUCCESS\n");
                else
                    printf("FAIL\n");
            }
        }
    }
    return 0;
}