//
// Created by 孙启龙 on 2016/11/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10010
#define abs(x) (x > 0 ? (x) : (-(x)))

using namespace std;

struct Node{
    int t, x;
    bool friend operator < (const Node &a, const Node &b)
    {
        return a.t < b.t;
    }
}node[maxn];
int T;
int sum;

int main (void)
{
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        scanf("%d", &sum);
        for(int i = 1; i <= sum; i++)
            scanf("%d %d", &node[i].t, &node[i].x);
        sort(node + 1, node + sum + 1);
        double maxx = -1;
        for(int i = 1; i < sum; i++)
            maxx = max(maxx,
                       (abs(node[i + 1].x - node[i]. x)) * 1.0 / (node[i + 1].t - node[i].t));
        printf("Case #%d: ", Case);
        printf("%.2lf\n", maxx);
    }
    return 0;
}