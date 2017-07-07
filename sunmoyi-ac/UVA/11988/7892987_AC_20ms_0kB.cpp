//
// Created by 孙启龙 on 2017/1/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int last, cur, nextt[maxn];
char s[maxn];

int main (void)
{
    while(scanf("%s", s + 1) == 1)
    {
        int n = strlen(s + 1);
        last = cur = 0;
        nextt[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            char ch = s[i];
            if(ch == '[')
                cur = 0;
            else if (ch == ']')
                cur = last;
            else
            {
                nextt[i] = nextt[cur];
                nextt[cur] = i;
                if(cur == last)
                    last = i;
                cur = i;
            }
        }
        for(int i = nextt[0]; i != 0; i = nextt[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}