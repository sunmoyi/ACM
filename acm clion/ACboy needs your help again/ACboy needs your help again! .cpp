//
// Created by 孙启龙 on 2017/7/18.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

int Case;
int n, num;
char cmd[100], op[100];

int main (void)
{
    while(scanf("%d", &Case) != EOF)
    {
        while(Case--)
        {
            scanf("%d %s", &n, cmd);
            if(strcmp(cmd, "FIFO") == 0)
            {
                queue<int>Q;
                for(int i = 0; i < n; i++)
                {
                    scanf("%s", op);
                    if(strcmp(op, "IN") == 0)
                    {
                        scanf("%d", &num);
                        Q.push(num);
                    }
                    else
                    {
                        if(!Q.empty())
                        {
                            printf("%d\n", Q.front());
                            Q.pop();
                        }
                        else
                            printf("None\n");
                    }
                }
            }
            else if (strcmp(cmd, "FILO") == 0)
            {
                stack<int>S;
                for(int i = 0; i < n; i++)
                {
                    scanf("%s", op);
                    if(strcmp(op, "IN") == 0)
                    {
                        scanf("%d", &num);
                        S.push(num);
                    }
                    else
                    {
                        if(!S.empty())
                        {
                            printf("%d\n", S.top());
                            S.pop();
                        }
                        else
                            printf("None\n");
                    }
                }
            }
        }
    }
    return 0;
}