//
// Created by 孙启龙 on 2016/10/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int T;
int N, K;
int num[maxn];

int main (void)
{
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        long long sum = 0;
        scanf("%d %d", &N, &K);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &num[i]);
            sum += num[i];
        }
        if(sum % K != 0)
        {
            printf("Case #%d: ", t);
            printf("-1\n");
        }
        else
        {
            int key = sum / K;
            int timee = 0;
            for(int i = 1; i <= N; i++)
            {
                if(num[i] >= key)
                {
                    timee += (num[i] / key);
                    num[i] -= num[i] / key * key;
                    if(num[i] == 0)
                        timee--;
                }
            }
            bool flag = 0;
            sum = 0;
            for(int i = 1; i <= N; i++)
            {
                if(num[i] != 0)
                {
                    sum += num[i];
                    timee++;
                    flag = 1;
                }
            }
            if(flag)
                timee--;
            if(sum != 0)
                timee += (sum / key) - 1;
            printf("Case #%d: ", t);
            printf("%d\n", timee);
        }
    }
    return 0;
}