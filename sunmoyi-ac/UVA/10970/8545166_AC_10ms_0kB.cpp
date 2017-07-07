//
// Created by 孙启龙 on 2017/3/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        printf("%d\n", n * m - 1);
    }
    return 0;
}