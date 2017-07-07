//
// Created by 孙启龙 on 2016/11/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 40

using namespace std;

struct point{
    int x, y;
    bool friend operator < (const point&a, const point&b)
    {
        if(a.x != b.x)
            return a.x < b.x;
        return
            a.y < b.y;
    }
}r[maxn];

struct sqare{
    point p1, p2;
    int area;
}sq[maxn * maxn];
int n;
int map[210][210];

int judge(sqare &a, sqare &b)
{
    if(a.p2.x < b.p1.x)
        return 1;
    if(a.p2.y < b.p1.y)
        return 1;
    if(b.p2.x < a.p1.x)
        return 1;
    if(b.p2.y < a.p1.y)
        return 1;
    if(a.p1.x < b.p1.x && a.p1.y < b.p1.y &&
            a.p2.x > b.p2.x && a.p2.y > b.p2.y)
        return 2;
    return 0;
}

int main (void)
{
    while (scanf("%d", &n) != EOF && n)
    {
        int cnt = 0;
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &r[i].x, &r[i].y);
            map[r[i].x][r[i].y] = 1;
        }
        sort(r + 1, r + n + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (r[i].y < r[j].y && r[i].x < r[j].x)
                {
                    if (map[r[j].x][r[i].y] && map[r[i].x][r[j].y])
                    {
                        sq[cnt].p1 = r[i];
                        sq[cnt].p2 = r[j];
                        sq[cnt++].area = (r[j].y - r[i].y) * (r[j].x - r[i].x);
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < cnt; j++)
            {
                if (judge(sq[i], sq[j]) == 1)
                    ans = max(ans, sq[i].area + sq[j].area);
                else if (judge(sq[i], sq[j]) == 2)
                    ans = max(ans, sq[i].area);
            }
        }
        if (ans == -1)
            printf("imp\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}