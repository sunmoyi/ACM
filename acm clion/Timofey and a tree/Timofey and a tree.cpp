//
// Created by 孙启龙 on 2017/2/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

int u[maxn], v[maxn], color[maxn], c[maxn],sum;

int main (void)
{
    int n;
    sum = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
        scanf("%d %d", &u[i], &v[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &color[i]);
    for(int i = 1; i < n; i++)
        if(color[u[i]] != color[v[i]])
            sum++, c[u[i]]++, c[v[i]]++;
    for(int i = 1; i <= n; i++)
    {
        if(c[i] == sum)
        {
            printf("YES\n%d\n", i);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}