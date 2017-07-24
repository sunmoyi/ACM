//
// Created by 孙启龙 on 2017/7/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1000010

using namespace std;

int a[maxn];
long long q[maxn];
long long T;
int n;

bool check(int x)
{
    int head = 0, tail = 0;
    int tmp = (n - 1) % (x - 1) + 1;
    long long ret = 0;
    long long cost = 0;
    int tot = 0;
    if(tmp != 1)
    {
        for(int i = 0; i < tmp; i++)
            ret += a[i];
        cost += ret;
        q[tail++] = ret;
        tot = tmp;
    }
    while(!(tot == n && head + 1 == tail))
    {
        int k = x;
        ret = 0;
        while(k)
        {
            k--;
            if(head == tail)
                ret += a[tot++];
            else
            {
                if(tot == n)
                    ret += q[head++];
                else
                {
                    if(a[tot] <= q[head])
                        ret += a[tot++];
                    else
                        ret += q[head++];
                }
            }
        }
        cost += ret;
        q[tail++] = ret;
    }
    if(cost > T)
        return false;
    return true;
}

int main (void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %lld", &n, &T);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int l = 2, r = n;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(check(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}