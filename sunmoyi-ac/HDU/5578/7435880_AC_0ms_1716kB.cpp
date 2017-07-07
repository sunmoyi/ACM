//
// Created by 孙启龙 on 2016/11/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[1500];
char str[1500];
int T;

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        for(int Case = 1; Case <= T; Case ++)
        {
            scanf("%s", str);
            memset(num, -1, sizeof(num));
            int minn = 0x3f3f3f3f;
            for(int i = 0; i < strlen(str); i++)
            {
                //printf("%c %d %d\n", str[i], num[str[i]], i);
                if(num[str[i]] == -1)
                {
                    num[str[i]] = i;
                }
                else if (minn > i - num[str[i]])
                {
                    minn = i - num[str[i]];
                    num[str[i]] = i;
                }
                else
                    num[str[i]] = i;
            }
            printf("Case #%d: ", Case);
            if(minn ==  0x3f3f3f3f)
                printf("-1\n");
            else
                printf("%d\n",  minn);
        }
    }
    return 0;
}