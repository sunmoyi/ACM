//
// Created by 孙启龙 on 2017/4/27.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int T;
int n;
struct node{
    long long weight;
    long long num;
}num[20010];
bool used[20010];

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &num[i].weight), num[i].num = 1, used[i] = true;

        int temp = n;
        long long minupdate = (1LL << 62), pos = 0;
        long long updatemin = (1LL << 62), updatapos = 0;
        while(temp > 3)
        {
            minupdate = (1LL << 62), pos = 0;
            updatemin = (1LL << 62), updatapos = 0;
            for(int i = 1; i <= n; i++)
            {
                if(used[i])
                {
                    if(minupdate > num[i].weight * num[i].num)
                    {
                        minupdate = num[i].weight * num[i].num;
                        pos = i;
                    }
                }
            }
            used[pos] = false;
            for(int i = 1; i <= n; i++)
            {
                if(used[i])
                {
                    long long change = (num[i].weight + num[pos].weight) * (num[i].num + num[pos].num) - num[i].weight * num[i].num;
                    if(updatemin > change)
                    {
                        updatemin = change;
                        updatapos = i;
                    }
                }
            }
            num[updatapos].weight += num[pos].weight;
            num[updatapos].num += num[pos].num;
            temp--;
        }

        long long ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(used[i])
                ans += num[i].weight * num[i].num;
        }
        printf("%lld\n", ans);
    }
    return 0;
}