//
// Created by 孙启龙 on 2016/11/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int sum;
double num[maxn];
double dis[maxn];
int T;

int main (void)
{
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d", &sum);
        num[0] = 0;
        for(int i = 1; i <= sum; i++)
        {
            scanf("%lf", &num[i]);
            dis[i] = num[i] - num[i - 1];
        }

        int time = 1;
        double speed = dis[sum];
        for(int i = sum - 1; i > 0; i--)
        {
            double timee = dis[i] / speed;
            int fintime = (int)timee;
            if(timee - (int)timee >= 1e-6)
                fintime++;
            speed = dis[i] / fintime;
            time += fintime;
        }
        printf("Case #%d: ", Case);
        printf("%d\n", time);
    }
    return 0;
}