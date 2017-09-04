//
// Created by 孙启龙 on 2017/8/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;

int main (void)
{
    int Case = 0;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(Case++)
            printf("\n");
        for(int i = min(n, m) + 1; i <= max(n, m) + 1; i++)
            printf("%d\n", i);
    }
    return 0;
}