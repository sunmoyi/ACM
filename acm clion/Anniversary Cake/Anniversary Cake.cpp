//
// Created by 孙启龙 on 2016/11/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int w, h;
int ax, ay, bx, by;

int main (void)
{
    freopen("anniversary.in", "r", stdin);
    freopen("anniversary.out", "w", stdout);
    while(scanf("%d %d %d %d %d %d", &h, &w, &ax, &ay, &bx, &by) != EOF)
    {
        if(ax != bx)
        {
            printf("%d %d %d %d\n", ax, 0, bx, w);
        }
        else
        {
            printf("%d %d %d %d\n", 0, ay, h, by);
        }
    }
    return 0;
}