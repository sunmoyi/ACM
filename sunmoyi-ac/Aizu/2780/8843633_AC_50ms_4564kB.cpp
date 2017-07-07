//
// Created by 孙启龙 on 2017/4/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define maxm 10100000

using namespace std;

int num[maxn];
int sum, ans;
int muli[maxm];

bool cmp(int a, int b)
{
    return a > b;
}

int main (void)
{
    while(scanf("%d", &sum) != EOF)
    {
        for(int i = 1; i <= sum; i++)
            scanf("%d", &num[i]);

        ans = 0;
        for(int i = 1; i < sum; i++)
            for(int j = i + 1; j <= sum; j++)
                muli[ans++] = num[i] * num[j];

        sort(muli, muli + ans, cmp);
        ans = (int)(unique(muli, muli + ans) - muli);
        sort(muli, muli + ans, cmp);

        bool flag = false;
        for(int i = 0; i < ans; i++)
        {
            int temp = muli[i];
            int x1 = temp % 10, x2 = 0;
            temp /= 10;
            bool found = true;
            while(temp > 0)
            {
                x2 = temp % 10;
                temp /= 10;
                if(x1 - x2 != 1)
                {
                    found = false;
                    break;
                }
                x1 = x2;
            }
            if(found)
            {
                flag = true;
                printf("%d\n", muli[i]);
                break;
            }
        }
        if(!flag)
            printf("-1\n");
    }
    return 0;
}