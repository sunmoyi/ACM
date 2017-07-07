//
// Created by 孙启龙 on 2017/3/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num, temp, ans = 0, now = 0;
bool has[100010];

int main (void)
{
    scanf("%d", &num);
    memset(has, false, sizeof(has));
    for(int i = 1; i <= (num << 1); i++)
    {
        scanf("%d", &temp);
        if(has[temp])
        {
            has[temp] = false;
            now--;
        }
        else
        {
            has[temp] = true;
            now++;
            ans = ans < now? now: ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}