//
// Created by 孙启龙 on 2017/10/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 100010

using namespace std;

pair<int, int>a[maxn];
int b[maxn];

int main(int agrc, char* agrv[])
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i].first), a[i].second = i;
        sort(a + 1, a + n + 1);

        for(int i = 2; i <= n; i++)
        {
            for(int j = n; j >= 1; j--)
            {
                if(a[j].second % i != 0)
                {
                    b[i] = a[j].first;
                    break;
                }
            }
        }
        for(int i = 2; i < n; i++)
            printf("%d ", b[i]);
        printf("%d\n", b[n]);
    }
    return 0;
}