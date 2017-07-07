//
// Created by 孙启龙 on 2016/11/27.
//

#include"myqueue.h"

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
    int v;
    node(int v = 0) : v(v) {}
};

vector<node>G[100];
int indgree[100];
int V, E;

bool topsort(void)
{
    int count = 0;
    queue Q;
    initqueue(&Q);
    for (int i = 0; i < V; i++)
    {
        if (indgree[i] == 0)
            Push(&Q, i);
    }
    while (!empty(&Q))
    {
        int t;
        Pop(&Q, &t);
        printf("%d \n", t);
        count++;
        for (int i = 0; i < G[t].size(); i++)
        {
            if (--indgree[G[t][i].v] == 0)
                Push(&Q, G[t][i].v);
        }
    }
    if (count < V)
        return false;
    else
        return true;
}

int main(void)
{
    int a, b, len;
    while (scanf("%d %d", &V, &E) != EOF)
    {
        memset(indgree, 0, sizeof(indgree));
        for (int i = 1; i <= E; i++)
        {
            scanf("%d %d", &a, &b);
            G[a].push_back(node(b));
            indgree[b]++;
        }
        bool flag = topsort();
        if (flag)
            printf("work down\n");
        else
            printf("Wrong");
    }
    return 0;
}