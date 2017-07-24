//
// Created by 孙启龙 on 2017/4/20.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define maxn 1000010
#define p 9901
#define mod 1000000007

using namespace std;

vector<int>G[maxn];
long long hashh[maxn];
map<long long, long long>mp;

void dfs(int u)
{
    hashh[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v);
        hashh[u] = (hashh[u] + hashh[v] * p) % mod;
    }
    mp[hashh[u]]++;
}

int main (void)
{
    int n;
    int u, v;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i <= n; i++)
            G[i].clear();
        mp.clear();

        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }
        dfs(1);
        long long ans = 0;
        for(map<long long, long long>:: iterator it = mp.begin(); it != mp.end(); it++)
            ans += it->second * (it->second - 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}