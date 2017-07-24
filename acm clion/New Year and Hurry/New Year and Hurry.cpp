//
// Created by 孙启龙 on 2017/1/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int fun(int a)
{
    return  ((1 + a) * a / 2) * 5;
}

int main (void)
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        if(b >= 240)
            printf("0\n");
        else
        {
            int i;
            for(i = 0; i <= a; i++)
            {
                if(fun(i) > 240 - b)
                    break;
            }
            printf("%d\n", i - 1);
        }
    }
}