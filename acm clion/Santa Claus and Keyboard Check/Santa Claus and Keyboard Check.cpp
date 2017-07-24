//
// Created by 孙启龙 on 2017/1/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str1[1100], str2[1100];
int vis[30], ans[30];

int main (void)
{
    while(scanf("%s", str1) != EOF)
    {
        scanf("%s", str2);
        memset(vis, 0, sizeof(vis));
        int len = strlen(str1), sum = 0;
        bool flag = true;
        for(int i = 0; i < len; i++)
        {
            if(!vis[str1[i] - 'a' + 1] && !vis[str2[i] - 'a' + 1])
            {
                vis[str1[i] - 'a' + 1] = str2[i] - 'a' + 1;
                vis[str2[i] - 'a' + 1] = str1[i] - 'a' + 1;
                if(str1[i] != str2[i])
                    ans[++sum] = str1[i] - 'a' + 1;
            }
            else if (str2[i] - 'a' + 1 != vis[str1[i] - 'a' + 1] ||
                    str1[i] - 'a' + 1 != vis[str2[i] - 'a' + 1])
                flag = false;
        }
        if(!flag)
            printf("-1\n");
        else
        {
            printf("%d\n", sum);
            for(int i = 1; i <= sum; i++)
                printf("%c %c\n", ans[i] + 'a' - 1, vis[ans[i]] + 'a' - 1);
        }
    }
    return 0;
}