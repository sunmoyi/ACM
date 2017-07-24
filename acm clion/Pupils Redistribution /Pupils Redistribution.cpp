//
// Created by 孙启龙 on 2017/5/11.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int num, temp;
int timee[10];

int main (void)
{
    scanf("%d", &num);
    memset(timee, 0, sizeof(timee));
    for(int i = 1; i <= num; i++)
    {
        scanf("%d", &temp);
        timee[temp]++;
    }
    for(int i = 1; i <= num; i++)
    {
        scanf("%d", &temp);
        timee[temp]--;
    }

    int ans = 0;
    for(int i = 0; i <= 5; i++)
    {
        if(timee[i] % 2 != 0)
        {
            printf("-1\n");
            return 0;
        }
        ans += abs(timee[i] * 1.0) /2;
    }
    printf("%d\n", ans / 2);
    return 0;
}