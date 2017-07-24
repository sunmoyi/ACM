//
// Created by 孙启龙 on 2017/4/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n1, n2, n3;
int m1, m2, m3;
int n;

int main (void)
{
    scanf("%d %d %d", &n1, &n2, &n3);
    scanf("%d %d %d", &m1, &m2, &m3);
    scanf("%d", &n);
    int sum1 = n1 + n2 + n3;
    int sum2 = m1 + m2 + m3;
    int ans1 = sum1 / 5;
    if(sum1 % 5)
        ans1++;
    int ans2 = sum2 / 10;
    if(sum2 % 10)
        ans2++;
    if(ans1 + ans2 <= n)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}