//
// Created by 孙启龙 on 2016/11/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1100

using namespace std;

char str[maxn];
int n, m, T;

int main (void)
{
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d %d", &n, &m);
        int a = max(n, m), b = min(n, m);
        getchar();
        for(int i = 1; i <= a * b; i++)
            scanf("%c", &str[i]);
        int kk = 1;
        for(int i = 1; i <= b; i++)
        {
            for(int j = 1; j<= a; j++)
            {
                printf("%c", str[kk]);
                kk++;
            }
            printf("\n");
        }
    }
    return 0;
}