//
// Created by 孙启龙 on 2017/8/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

char s[maxn];
int num[26];

int main (void)
{
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++)
    {
        memset(num, 0, sizeof(num));
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < len; i++)
            num[s[i] - 'a']++;
        int minn = 0x3f3f3f3f;
        for(int i = 0; i < 26; i++)
            if(num[i] < minn)
                minn = num[i];
        printf("Case %d: %d\n", Case, minn);
    }
    return 0;
}