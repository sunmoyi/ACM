#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int const MAXN = 200000+5;

vector<int>lin[MAXN];
int use[MAXN],n,m,flag,ff;
typedef pair<int,int> pp;

void init()
{
    flag = 0;
    memset(use,0,sizeof(use));
    for(int i=1;i<=n; i++)
        lin[i].clear();
    int s,e,val;
    while(m--)
    {
        scanf("%d%d%d",&s,&e,&val);
        val--;
        if(val)
        {
            if(use[s]==0)
                use[s] = val;
            else if(use[s] == -val)
            {
                flag=1;
                use[s]=val;
            }
            if(use[e]==0)
                use[e] = val;
            else if(use[e] == -val)
            {
                flag=1;
                use[e]=val;
            }
        }
        else
        {
            lin[s].push_back(e);
            lin[e].push_back(s);
        }
    }
}

void dfs1(int u,int father,int val)
{
    for(int i=0; i<lin[u].size(); i++)
    {
        int temp = lin[u][i];
        if(temp == father || use[temp] == -val)
            continue;
        if(use[temp] == val){
            flag = 1;
            return;
        }
        use[temp] = -val;
        dfs1(temp,u,-val);
    }
}

pp dfs2(int u,int father,int val)
{
    pp res = make_pair(0,0);
    if(val==1)
        res.first++;
    else
        res.second++;
    for(int i=0; i<lin[u].size(); i++)
    {
        if(lin[u][i] == father || use[lin[u][i]] == -val)
            continue;
        if(use[lin[u][i]]==val)
        {
            flag = 1;
            return res;
        }
        use[lin[u][i]] = -val;
        pp temp = dfs2(lin[u][i], u, -val);
        res.first += temp.first;
        res.second += temp.second;
    }
    return res;
}

void solve()
{
    if(flag)
    {
        printf("impossible\n");
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(use[i])
            dfs1(i,i,use[i]);
        if(flag)
        {
            printf("impossible\n");
            return;
        }
    }


    ff = 0;
    for(int i=1; i<=n; i++)
        if(use[i]==1)
            ff++;
    for(int i=1; i<=n; i++)
    {
        if(use[i])
            continue;
        use[i] = 1;
        pp tt = dfs2(i,i,1);
        if(flag)
            break;
        ff += min(tt.first,tt.second);
    }


    if(flag)
        printf("impossible\n");
    else
        printf("%d\n",ff);

}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        solve();
    }
    return 0;

}