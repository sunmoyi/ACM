//
// Created by 孙启龙 on 2017/4/22.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 10010;
struct node
{
    int dist, fuel;
};
node position[maxn];

int n, L, P;

bool cmp(const node &a, const node &b)
{
    return a.dist > b.dist;
}



int main()
{
    while(scanf("%d", &n) != EOF)
    {
        priority_queue<int> heap;
        for(int i = 0; i < n; i++)
            scanf("%d %d", &position[i].dist, &position[i].fuel);
        sort(position, position + n, cmp);
        scanf("%d %d", &L, &P);
        int t = 0;
        heap.push(P);
        int index = 0;
        while(L > 0 && !heap.empty())
        {
            t++;
            int tmp = heap.top();
            heap.pop();
            L -= tmp;
            while(index < n && L <= position[index].dist)
                heap.push(position[index++].fuel);
        }
        printf("%d\n", L <= 0? t - 1: -1);
    }

    return 0;
}