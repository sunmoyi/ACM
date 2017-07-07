//
// Created by 孙启龙 on 2016/11/17.
//

#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define maxn 1010

using namespace std;

int main (void)
{
    int T, Case = 1;
    while(scanf("%d", &T) != EOF && T)
    {
        printf("Scenario #%d\n", Case++);

        map<int, int>team;
        for(int i = 0; i < T; i++)
        {
            int n, x;
            scanf("%d", &n);
            while(n--)
            {
                scanf("%d", &x);
                team[x] = i;
            }
        }
        queue<int>q, q2[maxn];
        while(true)
        {
            int x;
            char cmd[100];
            scanf("%s", cmd);
            if(cmd[0] == 'S')
                break;
            else if (cmd[0] == 'D')
            {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if(q2[t].empty())
                    q.pop();
            }
            else if (cmd[0] == 'E')
            {
                scanf("%d", &x);
                int t = team[x];
                if(q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
