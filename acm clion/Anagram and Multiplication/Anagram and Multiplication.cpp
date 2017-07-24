//
// Created by 孙启龙 on 2017/3/28.
//

#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[7];
int vis[7];
int order[7];
int n,m;

bool solve(int x)
{
    for(int i = 2; i <= m; i++)
        order[i] = i;
    do {
        bool flag2 = true;
        for(int i = 2; i <= m; i++)
        {
            memset(vis,0,sizeof(vis));
            vis[i] = 1;
            int c = x * i / n;
            for(int j = 2; j <= m; j++)
            {
                int temp = (num[order[j]] * i + c) % n;
                c = (num[order[j]] * i + c) /n;
                bool flag = false;
                for(int k = 1; k <= m; k++)
                {
                    if(temp == num[k] && !vis[k])
                    {
                        vis[k] = 1;
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    flag2 = false;
                    break;
                }
            }
            if(!flag2)
                break;
        }
        if(flag2)
            return true;
    }while(next_permutation(order + 2, order + m + 1));
    return false;
}
int main()
{
    while(scanf("%d %d",&m,&n) && m)
    {
        bool flag = false;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                num[j] = (i * j) % n;//i是枚举的最后一位 num记录的是数字中的每一位
            }
            if(solve(i))
            {
                flag = true;
                for(int j = m; j >= 2; j--)
                    printf("%d ",num[order[j]]);
                printf("%d\n",i);
                break;
            }
        }
        if(!flag)
            printf("Not found.\n");
    }
}