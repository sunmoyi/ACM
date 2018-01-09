//
// Created by 孙启龙 on 2017/10/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define abs(x) ((x) > 0? (x):(-(x)))

using namespace std;

int x1, y1, x2, y2;

int main (void)
{
    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF)
    {
        if(x1 == x2 && y1 == y2)
            printf("%d\n", 10);
        else if(x1 == x2)
            printf("%d\n", abs(y1 - y2) * 2 + 6);
        else if (y1 == y2)
            printf("%d\n", abs(x1 - x2) * 2 + 6);
        else
            printf("%d\n", (abs(x1 - x2) + abs(y1 - y2)) * 2 + 4);
    }
}