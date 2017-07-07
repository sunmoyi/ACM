//
// Created by 孙启龙 on 2017/3/11.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define maxn 1010

using namespace std;

struct node{
    int price;
    int quality;
};
int n, b;
int cnt;
vector<node>comp[maxn];
map<string, int>id;

int ID(string s)
{
    if(!id.count(s))
        id[s] = cnt++;
    return id[s];
}

bool ok(int q)
{
    int sum = 0;
    for(int i = 0; i < cnt; i++)
    {
        int cheapest = b+1, m = comp[i].size();
        for(int j = 0; j < m; j++)
            if(comp[i][j].quality >= q)
                cheapest = min(cheapest, comp[i][j].price);
        if(cheapest == b+1)
            return false;
        sum += cheapest;
        if(sum > b)
            return false;
    }
    return true;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &b);

        cnt = 0;
        for(int i = 0; i < n; i++)
            comp[i].clear();
        id.clear();

        int maxq = 0;
        for(int i = 0; i < n; i++)
        {
            char type[30], name[30];
            int p, q;
            scanf("%s %s %d %d", type, name, &p ,&q);
            maxq = max(maxq, q);
            comp[ID(type)].push_back((node){p, q});
        }

        int L = 0, R = maxq;
        while(L < R)
        {
            int M = L + (R - L + 1) / 2;
            if(ok(M))
                L = M;
            else
                R = M - 1;
        }
        printf("%d\n", L);
    }
    return 0;
}
