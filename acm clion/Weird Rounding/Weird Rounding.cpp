//
// Created by 孙启龙 on 2017/5/11.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[100];
int num, numzero, len;

int main (void)
{
    scanf("%s %d", str, &num);
    len = (int)strlen(str);
    for(int i = 0; i < len; i++)
        if(str[i] == '0')
            numzero++;
    if(numzero < num)
        printf("%d\n", len - 1);
    else
    {
        int ans = 0, got = 0;
        for(int i = len - 1; got < num; i--)
        {
            if(str[i] == '0')
                got++;
            else
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}