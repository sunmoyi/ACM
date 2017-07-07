//
// Created by 孙启龙 on 2017/3/22.
//

#include<cstdio>  
#include<cstdlib>

using namespace std;

int n;
int main()
{
    int cases=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n < 0)
            break;
        int num = 1;
        int k = 0;
        while(1)
        {
            if(num >= n)
                break;
            num = num * 2;
            k++;
        }
        printf("Case %d: %d\n", ++cases, k);
    }
    return 0;
}  