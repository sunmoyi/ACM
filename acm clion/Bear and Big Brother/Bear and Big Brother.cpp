//
// Created by 孙启龙 on 2017/3/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    int a, b;
    int i = 0;
    scanf("%d %d", &a, &b);
    while(a <= b)
    {
        i++;
        a *= 3;
        b *= 2;
    }
    printf("%d\n", i);
    return 0;
}