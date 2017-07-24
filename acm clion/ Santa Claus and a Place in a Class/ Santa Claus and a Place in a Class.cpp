//
// Created by 孙启龙 on 2017/1/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int r = (k - 1) / (2 * m);
    int d = (k - 1) % (2 * m);
    if(k % 2 == 0)
        printf("%d %d R\n", r + 1, d / 2 + 1);
    else
        printf("%d %d L\n", r + 1, d / 2 + 1);
    return 0;
}