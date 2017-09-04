//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100

using namespace std;

int n[maxn] = {1, 1};
int num[maxn];
char str[maxn];
int ans = 0;

int main (void)
{
    for(int i = 2; i < 11; i++)
        n[i] = n[i - 1] * i;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        ans = 0;
        scanf("%s", str);
        int len = strlen(str);
        for(int i = 0; i < len; i++)
            num[i] = str[i] - '0';
        while(next_permutation(num, num + len))
            ans++;
        if(ans == 0)
            printf("%.9lf\n", double(0.00));
        else
        {
            double rate = 1.0 / n[len];
            double p = rate;
            for(int i = 1; i < ans; i++)
            {
                p = p + p * rate;
            }
            printf("%.9lf\n", p);
        }
    }
    return 0;
}