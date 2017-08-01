//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int xnsc, ynsc;
int n;
int nowx, nowy;
double minprice;

int main (void)
{
    scanf("%d %d", &xnsc, &ynsc);
    minprice = (1000.0 / ynsc) * (xnsc * 1.0);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &nowx, &nowy);
        double nowminprice = (1000.0 / nowy) * (nowx * 1.0);
        minprice = min(nowminprice, minprice);
    }
    printf("%.2lf\n", minprice);
    return 0;
}