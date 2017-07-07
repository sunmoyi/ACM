//
// Created by 孙启龙 on 2016/11/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[100010];
long long num[100010];
long long normal, maxx, T;

int main (void)
{
    while(scanf("%lld", &T) != EOF)
    {
        for(int Case = 1; Case <= T; Case++)
        {
            scanf("%s", str);
            int now = str[0], len = 1, sum = 1;
            memset(num, 0, sizeof(num));
            int kk = strlen(str);
            for(int i = 1; i < kk; i++)
            {
                if(str[i] == now)
                    len++;
                else
                {
                    now = str[i];
                    num[sum++] = len;
                    len = 1;
                }
            }
            num[sum++] = len;
            normal = maxx = 0;
            for(int i = 1; i < sum; i++)
            {
                normal += num[i] * num[i];
            }
            maxx = normal;
            for(int i = 1; i < sum; i++)
            {
                if(num[i] == 1)
                {
                    long long temp = normal;
                    temp -= (num[i - 1] * num[i - 1] + num[i] * num[i] + num[i + 1] * num[i + 1]);
                    temp += (num[i - 1] + num[i] + num[i + 1]) * (num[i - 1] + num[i] + num[i + 1]);
                    maxx = max(maxx, temp);
                }
                else
                {
                    long long temp1 = normal, temp2 = normal;
                    temp1 -= (num[i - 1] * num[i - 1] + num[i] * num[i]);
                    temp1 += ((num[i - 1] + 1) * (num[i - 1] + 1)  +   (num[i] - 1) * (num[i] - 1));
                    maxx = max(maxx, temp1);

                    temp2 -= (num[i] * num[i] + num[i + 1] * num[i + 1]);
                    temp2 += ((num[i] - 1) * (num[i] - 1)  +  (num[i + 1] + 1) * (num[i + 1] + 1));
                    maxx = max(maxx, temp2);
                }
            }
            printf("Case #%d: ", Case);
            printf("%lld\n", maxx);
        }
    }
    return 0;
}