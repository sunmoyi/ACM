//
// Created by 孙启龙 on 2016/11/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn];
int sum;
int t;
int T;

int main (void)
{
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        long long len = 0;
        scanf("%d %d", &sum, &t);
        for(int i = 1; i <= sum; i++)
        {
            scanf("%d", &num[i]);
            len += num[i];
        }
        printf("Case #%d: ", Case);
        if(len % t != 0)
        {
            printf("-1\n");
            continue;
        }
        int time = 0;
        long long key = len / t;
        len = 0;
        //printf("key: %lld\n", key);
        for(int i = 1; i <= sum; i++)
        {
            if(len == 0 && num[i] == key)
                continue;
            if(len != 0)
                time++;
            len += num[i];
            if(len && len % key == 0)
            {
                time += ((len / key) - 1);
                len = 0;
            }
            //printf("%d %d\n", i, time);
        }
        printf("%d\n", time);
    }
    return 0;
}