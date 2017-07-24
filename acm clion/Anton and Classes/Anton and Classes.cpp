//
// Created by 孙启龙 on 2017/3/22.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    int a, b;
    int max_1 = 0, max_2 = 0;
    int min_1 = 0x3f3f3f3f, min_2 = 0x3f3f3f3f;
    scanf("%d",&n);
    for(int i = 0;i < n; i++)
    {
        scanf("%d%d",&a,&b);
        max_1 = max(max_1,a);
        min_1 = min(min_1,b);
    }
    scanf("%d",&m);
    for(int i = 0;i < m; i++)
    {
        scanf("%d%d",&a,&b);
        max_2 = max(max_2,a);
        min_2 = min(min_2,b);
    }
    int x = max_2 - min_1;
    int y = max_1 - min_2;
    if(x<0 && y<0) puts("0");
    else printf("%d\n",max(x,y));

    return 0;
}