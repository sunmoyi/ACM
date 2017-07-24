//
// Created by 孙启龙 on 2017/4/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int a, b;
int ans;

int main (void)
{
    scanf("%d %d", &a, &b);
    while(a > 0 && b > 0)
    {
        ans++;
        if(a > b)
        {
            a -= 2;
            b += 1;
        }
        else
        {
            a += 1;
            b -= 2;
        }
        if(a < 0 || b < 0)
            ans--;
    }
    printf("%d\n", ans);
    return 0;
}