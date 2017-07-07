//
// Created by 孙启龙 on 2017/1/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    int T, D, I;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &D, &I);
        int k = 1;
        for(int i = 0; i < D - 1; i++)
        {
            if(I % 2 == 1)
            {
                k = k * 2;
                I = (I + 1) / 2;
            }
            else
            {
                k = k * 2 + 1;
                I /= 2;
            }
        }
        printf("%d\n", k);
    }
    return 0;
}