//
// Created by 孙启龙 on 2017/8/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <cmath>

#define maxn 1000010

using namespace std;

int sum[maxn];

bool judge(int n)
{
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    for(int i = 2; i <= sqrt(n * 1.0); i++)
        if(n % i == 0)
            return false;
    return true;
}

void init()
{
    sum[0] = 0;
    for(int i = 1; i < maxn; i++)
    {
        int temp = i;
        int cont = 0;
        while(temp)
        {
            if(temp % 2)
                cont++;
            temp >>= 1;
        }
        sum[i] = sum[i - 1];
        if(judge(cont))
            sum[i]++;
    }
}

int main (void)
{
    int T;
    init();
    scanf("%d", &T);
    int x, y;
    while(T--)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", sum[y] - sum[x - 1]);
    }
    return 0;
}