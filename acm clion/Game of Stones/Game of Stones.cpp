//
// Created by 孙启龙 on 2017/5/19.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, temp, ans;

int main (void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        int timee = 1;
        temp--;
        while(temp > timee)
        {
            timee++;
            temp -= timee;
        }
        ans = (i == 1)? timee: ans ^ timee;
    }
    if(ans == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}