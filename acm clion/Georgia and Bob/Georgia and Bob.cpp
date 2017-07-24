//
// Created by 孙启龙 on 2017/4/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010

using namespace std;

int num[maxn];
int sum;

int main (void)
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        scanf("%d", &sum);
        for(int i = 1; i <= sum; i++)
            scanf("%d", &num[i]);
        sort(num + 1, num + sum + 1);

        int ans = 0;
        for(int i = sum; i > 0; i -= 2)
        {
            int temp = 0;
            if(i == 1)
                temp = num[i] - 1;
            else
                temp = num[i] - num[i - 1] - 1;
            ans ^= temp;
        }
        if(!ans)
            printf("Bob will win\n");
        else
            printf("Georgia will win\n");
    }
    return 0;
}