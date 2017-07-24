//
// Created by 孙启龙 on 2017/7/18.
//

#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long L,R;
    while(~scanf("%lld%lld",&L,&R))
    {
        if(R<=1)
        {
            printf("0\n");
            continue;
        }
        if(R<=2)
        {
            printf("1\n");
            continue;
        }
        if(L==0)L++;
        printf("%lld\n",max(2LL,(R-L)/2+1));
    }


    return 0;
}