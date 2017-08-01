//
// Created by 孙启龙 on 2017/7/26.
//

#include<cstdio>
#include<cmath>
int main()
{
    double lg=log10(2.00000);
    int kase=1;
    double m;
    int res=0;
    while(scanf("%lf",&m)!=EOF)
    {
        res=(int )(m*lg);
        printf("Case #%d: %d\n",kase++,res);
    }
    return 0;
}