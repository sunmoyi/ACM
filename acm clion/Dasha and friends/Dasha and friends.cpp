//
// Created by 孙启龙 on 2017/2/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int chaa[1000];
int chab[1000];
int a[1000];
int b[1000];
int c[1000];

int main (void)
{
    int n, l;
    while(scanf("%d %d", &n, &l) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &b[i]);

        for(int i = 1; i <= n; i++)
        {
            chaa[i] = a[i] - a[i + 1];
            if(i == n)
                chaa[i] = a[i] - a[1];
            if(chaa[i] < 0)
                chaa[i] += l;
        }
        for(int i = 1; i <= n; i++)
        {
            chab[i] = b[i] - b[i + 1];
            if(i == n)
                chab[i] = b[i] - b[1];
            if(chab[i] < 0)
                chab[i] += l;
        }

        int ok = 0;
        for(int i = 1; i <= n; i++)
        {
            int cnt = 1;
            for(int j = i; j <= n; j++)
                c[cnt++] = chaa[j];
            for(int j = 1; j < i; j++)
                c[cnt++] = chaa[j];
            int flag = 0;
            for(int j = 1; j <= n; j++)
            {
                if(chab[j] == c[j])
                    continue;
                else
                    flag = 1;
            }
            if(flag == 0)
                ok = 1;
        }
        if(ok == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}