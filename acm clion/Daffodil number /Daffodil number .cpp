//
// Created by 孙启龙 on 2017/1/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans;

int main (void)
{
    while(scanf("%d", &ans) != EOF)
    {
        int a = ans % 10;
        int b = (ans / 10) % 10;
        int c = (ans / 100) % 10;
        if(a * a * a + b * b * b + c * c * c == ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}