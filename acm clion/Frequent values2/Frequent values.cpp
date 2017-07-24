//
// Created by 孙启龙 on 2017/5/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010

using namespace std;

int maxsum[maxn][20];
int num[maxn];
int n, k;

void RMQinit()
{
    for(int j=1;j<=19;j++)
        for(int i=1;i<=n;i++)
            if(i + (1 << j) - 1 <= n)
                maxsum[i][j]=max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
}

int getmax(int x,int y)
{
    int m = log(double(y-x+1))/log(2.0);
    return max(maxsum[x][m],maxsum[y-(1<<m)+1][m]);
}

int main(void)
{
    int x, y;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            if(i == 1)
                maxsum[i][0] = 1;
            else if (num[i] == num[i - 1])
                maxsum[i][0] = maxsum[i - 1][0] + 1;
            else
                maxsum[i][0] = 1;
        }

        RMQinit();

        while(k--)
        {
            scanf("%d %d", &x, &y);
            int temp = x;
            while(temp <= y && num[temp] == num[temp - 1])
                temp++;
            int ans = temp - x;
            if(temp <= y)
                ans = max(ans, getmax(temp, y));
            printf("%d\n", ans);
        }
    }
    return 0;
}