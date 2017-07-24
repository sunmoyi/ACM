//
// Created by 孙启龙 on 2017/4/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn][100];
int data[maxn];
int T, n;

void devide()
{
    for(int i = 1; i <= n; i++)
    {
        int t = 1;
        int temp = data[i];
        while(temp > 0)
        {
            if(temp % 2 == 0)
                num[i][t] = num[i - 1][t] + 1;
            else
                num[i][t] = num[i - 1][t];
            temp /= 2;
            t++;
        }
    }
}

int highone(int a)
{
    return a == 1? 1: highone(a / 2) + 1;
}

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
            for(int i = 1; i <= n; i++)
                scanf("%d", &data[i]);
            sort(data + 1, data + n + 1);

            devide();

            long long ans = 0;
            for(int i = 1; i < n; i++)
            {
                int temp = highone(data[i]);
                //printf("high: %d   ", temp);
                int temp2 = num[n][temp] - num[i][temp];
                //printf("%d %d\n", num[n][temp], num[i][temp]);
                ans += temp2;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}