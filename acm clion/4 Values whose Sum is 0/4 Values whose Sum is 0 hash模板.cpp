//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define size 20345677
#define key 745
#define maxm 4010

using namespace std;

int n, a[maxm], b[maxm], c[maxm], d[maxm], ans;
int hashh[size], sum[size];

void insert(int num)
{
    int temp = num;
    num = (num + INF) % size;
    while(hashh[num] != INF && hashh[num] != temp)
        num = (num + key) % size;
    hashh[num] = temp;
    sum[num]++;
}

int find(int num)
{
    int temp = num;
    num = (num + INF) % size;
    while(hashh[num] != INF && hashh[num] != temp)
        num = (num + key) % size;
    if(hashh[num] == INF)
        return 0;
    else
        return sum[num];
}

int main (void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    memset(hashh, 0x3f, sizeof(hashh));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            insert(a[i] + b[j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans += find(-c[i] - d[j]);
    printf("%d\n", ans);
    return 0;
}