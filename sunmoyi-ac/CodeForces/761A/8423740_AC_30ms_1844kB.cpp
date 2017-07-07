//
// Created by 孙启龙 on 2017/2/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

int a, b;

int main (void)
{
    scanf("%d %d", &a, &b);
    if(a == 0 && b == 0)
        printf("NO\n");
    else if (abs(a - b) == 1 || abs(a - b) == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}