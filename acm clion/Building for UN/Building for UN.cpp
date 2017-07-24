//
// Created by 孙启龙 on 2017/2/13.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char country(int i)
{
    if(i < 26)
        return 'A' + i;
    else
        return 'a' + i - 26;
}

int main (void)
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        printf("2 %d %d\n", n, n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%c", country(i));
            printf("\n");
        }
        printf("\n");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                printf("%c", country(j));
            printf("\n");
        }
    }
    return 0;
}