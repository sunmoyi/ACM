//
// Created by 孙启龙 on 2017/8/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

int ques[maxn][5];
char qu, an;
int n, m;
int T;

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        memset(ques, 0, sizeof(ques));
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%*c%c%*c%c", &qu, &an);
                if(an == 'T')
                    ques[j][qu - 'A'] = 1;
                else
                    ques[j][qu - 'A'] = -1;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            char ans;int flag = 0;
            for(int j = 0; j < 4; j++)
            {
                if(ques[i][j] == 1)
                {
                    printf("%c%c", 'A' + j, i == n? '\n': ' ');
                    goto end;
                }
                else if(ques[i][j] == 0)
                {
                    ans = 'A' + j;
                }
                else if (ques[i][j] == -1)
                    flag++;
            }
            if(flag == 3)
                printf("%c%c", ans, i == n? '\n': ' ');
            else
                printf("?%c", i == n? '\n': ' ');
            end:
                ;
        }
    }
}
