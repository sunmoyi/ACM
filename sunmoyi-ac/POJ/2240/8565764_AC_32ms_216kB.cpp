//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>

#define INF 0x3f3f3f3f
#define maxn 50

using namespace std;

double rate;
double dist[maxn][maxn];
char str[maxn], str1[maxn], str2[maxn];
int i, j, k, n, m;
map<string, int>STL;

void floyed(void)
{
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (dist[i][j] < dist[i][k] * dist[k][j])
                    dist[i][j] = dist[i][k] * dist[k][j];
    return;
}

int main (void)
{
    int Case = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        memset(dist, 0x3f, sizeof(dist));
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            STL[str] = i;
            dist[i][i] = 1;
        }

        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
        {
            scanf("%s %lf %s", str1, &rate, str2);
            dist[STL[str1]][STL[str2]] = rate;
        }

        floyed();

        int flag = false;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i][i] > 1)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            printf("Case %d: Yes\n", Case++);
        else
            printf("Case %d: No\n", Case++);
    }
}