//
// Created by 孙启龙 on 16/10/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 249997

using namespace std;

int hash1[maxn], coun[maxn];
int ans;

unsigned int BKDhash(char str[])
{
    unsigned int seed = 131;
    unsigned int hashh = 0;

    while(*str)
    {
        hashh = hashh * seed + (*str++);
    }
    return (hashh % maxn);
}

void hashit(char str[])
{
    while(*str == '0')
        str++;
    int k = BKDhash(str);
    int t = k % maxn;
    while(hash1[t] != -1 && hash1[t] != k)
        t = (t + 10) % maxn;
    if(hash1[t] == -1)
        hash1[t] = k, coun[t] = 1;
    else
    {
        coun[t]++;
        if(coun[t] > ans)
            ans = coun[t];
    }
}

int main (void)
{
    int N;
    char str[100];
    while(scanf("%d", &N) != EOF)
    {
        memset(hash1, -1, sizeof(hash1));
        ans = 1;
        getchar();
        while(N--)
        {
            gets(str);
            hashit(str);
        }
        printf("%d\n", ans);
    }
    return 0;
}