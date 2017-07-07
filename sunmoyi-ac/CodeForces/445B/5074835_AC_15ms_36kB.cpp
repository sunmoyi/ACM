#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 55;
int intree[maxn];
vector<int> G[maxn];

void dfs(int e)
{
    intree[e] = 1;
    for(int i=0;i<G[e].size();i++)
    {
        if(intree[G[e][i]] == 0)
        {
            //intree[G[e][i]] = true;
            dfs(G[e][i]);
        }
    }
    return ;
}

void Init()
{
    for(int i=0;i<maxn;i++){
        G[i].clear();
        intree[i] = 0;
    }
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        Init();
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        //memset(intree,0,sizeof(intree));
        int num = 0;
        for(int i=1;i<=n;i++)
        {
            if(intree[i] == 0)
            {
                num++;
                //cout<<num<<endl;
                dfs(i);
            }
        }
        __int64 k = 1;
        int len = n-num;
        for(int i=0;i<len;i++){
            //cout<<k<<endl;
            k *= 2;
        }
        printf("%I64d\n",k);
    }
    return 0;
}
