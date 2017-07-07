#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 20020

using namespace std;

int num[maxn];
int sum, k;

int main (void)
{
    while(scanf("%d %d", &sum, &k) != EOF)
    {
        for(int i = 0; i < sum; i++)
            scanf("%d", &num[i]);
        sort(num, num + sum);

        int ans = 0;
        for(int i = 1; i < sum; i++)
        {
            int temp = upper_bound(num, num + i, k - num[i]) - num;
            //temp = sum - temp;
            //printf("%d %d %d\n", i, num[i], temp);
            ans += temp;
        }
        printf("%d\n", ans);
    }
    return 0;
}