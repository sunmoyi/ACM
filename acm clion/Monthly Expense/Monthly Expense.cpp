//
// Created by 孙启龙 on 2017/4/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 100010

using namespace std;

int a[maxn];
int N, M;

bool check(int mid)
{
    int sum = 0;
    int len = 1;
    for(int i = 1; i <= N; i++)
    {
        if(sum + a[i] <= mid)
        {
            sum += a[i];
        }
        else
        {
            sum = a[i];
            len++;
        }
    }
    return len <= M;
}

int main (void)
{
    while(cin >> N >> M)
    {
        int high = 0, low = 0;
        for(int i = 1; i <= N; i++)
        {
            cin >> a[i];
            high += a[i];
            if(low < a[i])
                low = a[i];
        }

        int ans = low;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if (!check(mid))
            {
                low = mid + 1;
            }
            else
            {
                ans = high;
                high = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}