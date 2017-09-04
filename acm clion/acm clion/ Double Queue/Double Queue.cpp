//
// Created by 孙启龙 on 2017/3/4.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

map<int, int>mp;
int cmd, key, lv;

int main (void)
{
    while(scanf("%d", &cmd) != EOF && cmd)
    {
        if(cmd == 1)
        {
            scanf("%d %d", &key, &lv);
            mp[lv] = key;
        }
        else if (cmd == 2)
        {
            int ans = 0;
            if(mp.size() == 0)
                printf("0\n");
            else
            {
                ans = (--mp.end())->second;
                mp.erase(--mp.end());
                printf("%d\n", ans);
            }
        }
        else if (cmd == 3)
        {
            int ans = 0;
            if(mp.size() == 0)
                printf("0\n");
            else
            {
                ans = (mp.begin())->second;
                mp.erase(mp.begin());
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}