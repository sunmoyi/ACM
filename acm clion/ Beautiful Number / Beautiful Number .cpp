//
// Created by 孙启龙 on 2017/1/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a = 1, b = 1;
int ans[100010];

int main (void)
{
    for(int i = 1; i <= 100005; i++)
    {
        int aa = a * 3;
        int bb = b * 5;
        if(aa < bb)
        {
            ans[i] = aa;
            ++a;
        }
        else if (aa > bb)
        {
            ans[i] = bb;
            ++b;
        }
        else
        {
            ++a;
            ++b;
            ans[i] = aa;
        }
    }
    int temp;
    while(scanf("%d", &temp) != EOF)
    {
        printf("%d\n", ans[temp]);
    }
    return 0;
}