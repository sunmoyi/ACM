//
// Created by 孙启龙 on 2017/2/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int x[] = {0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
int main (void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        printf("%d\n", ((x[n] - 8 + m) % 7 == 0)? ((x[n] - 8 + m) / 7 + 1) : ((x[n] - 8 + m) / 7 + 2));
    }
    return 0;
}