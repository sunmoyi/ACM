//
// Created by 孙启龙 on 2017/4/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 11000

using namespace std;

int num[maxn], sum;

bool check1()
{
    if(sum < 10 || sum > 13)
        return false;
    else
        return true;
}

bool check2()
{
    if(num[1] != 1)
        return false;
    else
        return true;
}

bool check3()
{
    if(num[1] == num[2] && num[1] == 1)
        return true;
    else
        return false;
}

bool check4()
{
    for(int i = 1; i < sum - 1; i++)
        if(num[i + 1] - num[i] > 2)
            return false;
    return true;
}

int main (void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d", &sum);
            for(int i = 1; i <= sum; i++)
                scanf("%d", &num[i]);
            sort(num + 1, num + sum + 1);

            if(check1() && check2() && check3() && check4())
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}