//
// Created by 孙启龙 on 2017/2/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int main (void)
{
    int T, n, l, a[100010];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &l);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        sort(a, a + n);

        int left = 0, right = n - 1;
        int ans = 0;
        while(left <= right)
        {
            if(a[left] + a[right] > l)
                --right;
            else
            {
                ++left;
                --right;
            }
            ++ans;
        }
        printf("%d\n", ans);
        if(T)
            printf("\n");
    }
    return 0;
}