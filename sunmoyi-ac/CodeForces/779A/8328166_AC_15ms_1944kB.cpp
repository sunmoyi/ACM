//
// Created by 孙启龙 on 2017/3/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define abs(x) ((x) > 0? (x): (-(x)))

using namespace std;

int a[maxn], b[maxn];
int sum, temp;
int num[maxn];

int main(void)
{
    while(scanf("%d", &sum) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= sum; i++)
        {
            scanf("%d", &temp);
            a[temp]++;
        }
        for(int i = 1; i <= sum; i++)
        {
            scanf("%d", &temp);
            b[temp]++;
        }

        bool flag = true;
        int ans = 0;
        for(int i = 1; i <= 5; i++)
        {
            if((a[i] + b[i]) % 2)
                flag = false;
            ans += abs(a[i] - b[i]) / 2;
        }
        if(flag)
            printf("%d\n", ans / 2);
        else
            printf("-1\n");
    }
}