//
// Created by 孙启龙 on 2017/1/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int main (void)
{
    int n;
    scanf("%d", &n);
    int high_div2 = -INF;
    int low_div1 = INF;
    int so_far = 0;
    for(int i = 0; i < n; i++)
    {
        int change, divsion;
        scanf("%d %d", &change, &divsion);
        if(divsion == 2)
            high_div2 = max(high_div2, so_far);
        else
            low_div1 = min(low_div1, so_far);
        so_far += change;
    }
    if(high_div2 == -INF)
        printf("Infinity\n");
    else if ( high_div2 >= low_div1)
        printf("Impossible\n");
    else
        printf("%d\n", 1899 - high_div2 + so_far);
    return 0;
}