//
// Created by 孙启龙 on 2017/3/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int buf[100];

int next(int n, int k)
{
    if(!k)
        return 0;
    long long k2 = (long long)k * k;
    int L = 0;
    while(k2 > 0)
    {
        buf[L++] = k2 % 10;
        k2 /= 10;
    }
    if(n > L)
        n = L;
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = ans * 10 + buf[--L];
    return ans;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int ans = k;
        int k1 = k, k2 = k;
        do{
            k1 = next(n, k1);
            k2 = next(n, k2);
            if(k2 > ans)
                ans = k2;
            k2 = next(n, k2);
            if(k2 > ans)
                ans = k2;
        }while(k1 != k2);
        printf("%d\n", ans);
    }
    return 0;
}