//
// Created by 孙启龙 on 2017/1/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1000005
#define mod 1000000007

using namespace std;

vector<int>a[1000010];
int sum, n, m, temp;

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &sum);
            for(int j = 1; j <= sum; j++)
            {
                scanf("%d", &temp);
                a[temp].push_back(i);
            }
        }

        sort(a, a + m + 1);

        long long ans = 1;
        temp = 1;
        for(int i = 2; i <= m; i++)
        {
            if(a[i] == a[i - 1])
            {
                temp++;
                ans = (ans * temp) % mod;
            }
            else
                temp = 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}