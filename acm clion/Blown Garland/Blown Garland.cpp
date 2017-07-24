//
// Created by 孙启龙 on 2017/2/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[110];

int main (void)
{
    scanf("%s", str);
    int n = strlen(str), res[4] = {0}, tot[4] = {0}, cnt[4] = {0};
    for(int i = 0; i < n; i++)
    {
        tot[i % 4]++;
        if(str[i] == 'R')
            res[0] = i % 4, cnt[0]++;
        if(str[i] == 'B')
            res[1] = i % 4, cnt[1]++;
        if(str[i] == 'Y')
            res[2] = i % 4, cnt[2]++;
        if(str[i] == 'G')
            res[3] = i % 4, cnt[3]++;
    }
    for(int i = 0; i < 4; i++)
        printf("%d ", tot[res[i]] - cnt[i]);
    //printf("\n");
    return 0;
}