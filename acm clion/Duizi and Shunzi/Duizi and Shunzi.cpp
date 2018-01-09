//
// Created by 孙启龙 on 2017/9/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1000000 + 10;
int num[N];

int main()
{
    int n, x;
    while(~ scanf("%d", &n))
    {
        memset(num, 0, sizeof num);
        for(int i = 1; i <= n; i++) scanf("%d", &x), num[x]++;
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i <= 2)
            {
                ans += num[i] / 2;
                num[i] %= 2;
            }
            else
            {
                if(num[i] && num[i-1] && num[i-2])
                {
                    num[i]--; num[i-1]--, num[i-2]--;
                    ans++;
                }
                ans += num[i] / 2;
                num[i] %= 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}