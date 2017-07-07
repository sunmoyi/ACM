//
// Created by 孙启龙 on 2017/1/25.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

int cur = 0;
char str[100000000];
map<long long, int>cnt;

void dfs(int dep)
{
    if(isdigit(str[cur]))
    {
        long long a = 0;
        while(isdigit(str[cur]))
            a = a * 10 + str[cur++] - '0';
        cnt[a << dep]++;
    }
    else
    {
        cur++;
        dfs(dep + 1);
        cur++;
        dfs(dep + 1);
        cur++;
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        cnt.clear();
        cur = 0;
        scanf("%s", str);
        dfs(0);
        int mx = -1, sum = 0;
        for(map<long long, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
            sum += it->second, mx = max(mx, it->second);
        printf("%d\n", sum - mx);
    }
    return 0;
}