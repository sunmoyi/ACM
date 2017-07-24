//
// Created by 孙启龙 on 2017/5/13.
//

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn =  1e3 +5;
struct node {
double r , l;
}sec[maxn];

bool cmp(node a , node b)
{

    if(a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}

int main()
{
    int n , d;
    int kase = 1;
    while(scanf("%d%d" , &n , &d) != EOF)
    {
        if(n == 0 && d == 0)
            break;
        int index = 0;
        int flagg = 0;
        if(d < 0)
            flagg = 1;
        int  x , y;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d" , &x , &y);
            if(d  - abs(y*1.0) < 0)
            {
                flagg = 1;
                continue;
            }
            double deta = sqrt((double)(d * d - y * y));
            sec[index].l = (double)x - deta;
            sec[index].r = (double)x + deta;
            index++;
        }
        getchar();
        getchar();
        if(flagg)
        {
            printf("Case %d: -1\n" , kase++);
            continue;
        }

        sort(sec , sec + index , cmp);
        int ans = 0;
        bool vis[maxn];
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < index; i ++)
        {
            if(!vis[i])
            {
                ans++;
                vis[i] = true;
                for(int j = i + 1; j < index; j++)
                {
                    if(!vis[j] && sec[i].r >= sec[j].l)
                        vis[j] = true;
                }
            }
        }
        printf("Case %d: %d\n" , kase++ , ans);
    }
}