//
// Created by 孙启龙 on 2017/4/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

map<long long, long long>mp;
char str[100000];
int num[30];
int T, len;

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%s", str);
            len = strlen(str);
            mp.clear();
            mp[0]++;
            memset(num, 0, sizeof(num));
            for(int i = 0; i < len; i++)
            {
                num[str[i] - 'a']++;
                long long temp = 0;
                for(int i = 0; i < 26; i++)
                {
                    if(num[i] % 2)
                    {
                        temp *= 2;
                        temp++;
                    }
                    else
                        temp++;
                }
                mp[temp]++;
            }
            long long ans = 0;
            for(map<long long, long long>::iterator it = mp.begin(); it != mp.end(); it++)
                ans += it->second * (it->second) / 2;
            printf("%lld\n", ans);
        }
    }
    return 0;
}