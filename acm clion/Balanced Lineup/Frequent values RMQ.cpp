//
// Created by 孙启龙 on 2017/5/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#define maxn 50010

using namespace std;

int maxsum[maxn][18];
int minsum[maxn][18];
int n, k;

void RMQinit()
{
    for(int j=1;j<=16;j++)
        for(int i=1;i<=n;i++)
            if(i + (1 << j) - 1 <= n)
            {
                maxsum[i][j]=max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
                minsum[i][j]=min(minsum[i][j-1],minsum[i+(1<<(j-1))][j-1]);
            }
}

int getmax(int x,int y)
{
    int m=log(double(y-x+1))/log(2.0);
    return max(maxsum[x][m],maxsum[y-(1<<m)+1][m]);
}

int getmin(int x,int y)
{
    int m=log(double(y-x+1))/log(2.0);
    return min(minsum[x][m],minsum[y-(1<<m)+1][m]);
}

int main (void)
{
    int x, y;
    srand((unsigned int)time(0));
    printf("%d %d\n", rand() % 9, rand() % 24);
    while(scanf("%d %d", &n, &k) != EOF)
    {
        memset(maxsum,0,sizeof(maxsum));
        memset(minsum,0,sizeof(minsum));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &maxsum[i][0]);
            minsum[i][0] = maxsum[i][0];
        }
        RMQinit();
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d", &x, &y);
            //cout << getmax(x, y) << endl;
            //cout << getmin(x, y) << endl;
            cout << getmax(x, y) - getmin(x, y) << endl;
        }
    }
    return 0;
}