//
// Created by 孙启龙 on 2017/8/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1024

using namespace std;

int T;
int n;
char str[4][maxn];

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
            for(int i = 1; i <= 3; i++)
                scanf("%s", str[i] + 1);

            int ans = 0;
            for(int i = 1; i <= n; i++)
            {
                int temp = 0;
                for(int j = 1; j <= 3; j++)
                    for(int k = i * 3 - 2; k <= i * 3; k++)
                        if(str[j][k] == '*')
                            temp++;
                ans = max(ans, temp << 2);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}