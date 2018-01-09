//
// Created by 孙启龙 on 2017/10/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int a;
        scanf("%d", &a);
        int ans = (a + 1) / 2 + 1;
        printf("%d\n", ans);
    }
    return 0;
}