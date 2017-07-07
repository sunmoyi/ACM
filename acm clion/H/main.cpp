//
// Created by 孙启龙 on 2016/11/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

int n, num1[maxn], num2[maxn];
int ans1[maxn * 2], ans2[maxn];
int nextt[maxn * 2];

void makenext()
{
    int i = 0, j = -1;
    nextt[0] = -1;
    while(i < n)
    {
        if(j == -1 || ans2[i] == ans2[j])
        {
            i++;
            j++;
            nextt[i] = j;
        }
        else
            j = nextt[j];
    }
}

bool kmp()
{
    makenext();
    int i = 0, j = 0 ;
    while(i < n * 2 && j < n)
    {
        if(ans1[i] == ans2[j] || j == -1)
        {
            i++, j++;
        }
        else
            j = nextt[j];
    }
    if(j == n)
        return true;
    return false;
}

int main (void)
{
    scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num1[i]);
            //num1[i] %= 360;
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num2[i]);
            //num2[i] %= 360;
        }
        sort(num1, num1 + n);
        sort(num2, num2 + n);

        for(int i = 0; i < n - 1; i++)
        {
            ans1[i] = num1[i + 1] - num1[i];
            ans2[i] = num2[i + 1] - num2[i];
        }
        ans1[n - 1] = 360000 - num1[n - 1] + num1[0];
        ans2[n - 1] = 360000 - num2[n - 1] + num2[0];
/*
        for(int i = 0; i < n; i++)
            printf("%d ", ans1[i]);
        printf("\n");
        for(int i = 0; i < n; i++)
            printf("%d ", ans2[i]);
        printf("\n");
*/
        for(int i = n; i < n * 2; i++)
            ans1[i] = ans1[i - n];
        if(kmp())
            printf("possible\n");
        else
            printf("impossible\n");
    return 0;
}