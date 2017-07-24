//
// Created by 孙启龙 on 2017/4/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[100];
bool num[100];
int node[1010];
int k;

bool dfs(int step, int last, int minn, int maxx)
{
    for(int i = 1; i <= 10; i++)
    {
        if(!num[i])
            continue;
        if(i == last)
            continue;
        if(minn + i <= maxx)
            continue;
        node[step] = i;
        if(step == k)
        {
            printf("YES\n");
            for(int j = 1; j <= step; j++)
                printf("%d ", node[j]);
            return true;
        }
        if(dfs(step + 1, i, maxx, minn + i))
            return true;
    }
    return false;
}

int main (void)
{
    scanf("%s", str);
    scanf("%d", &k);
    for(int i = 0; i < 10; i++)
        if(str[i] == '1')
            num[i + 1] = true;
    if(!dfs(1, -1, 0, 0))
        printf("NO\n");
    return 0;
}