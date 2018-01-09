//
// Created by 孙启龙 on 2017/10/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a, b, c, ab, bc, ac, abc;
int ans, sum;

int main (void)
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        scanf("%d", &sum);
        ans = 0;
        while (sum--) {
            scanf("%d %d %d %d %d %d %d", &a, &b, &c, &ab, &bc, &ac, &abc);
            ac -= abc;
            ab -= abc;
            bc -= abc;
            a -= (ab + ac + abc);
            b -= (ab + bc + abc);
            c -= (ac + bc + abc);
            //printf("%d %d %d %d %d %d %d\n", a, b, c, ab, ac, bc, abc);
            if (abc < 0 || ac < 0 || ab < 0 || bc < 0 || a < 0 || b < 0 || c < 0)
                continue;
            else
                ans = max(ans, a + b + c + ab + ac + bc + abc);
        }
        printf("%d\n", ans);
    }
    return 0;
}