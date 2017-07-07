//
// Created by 孙启龙 on 2016/02/03.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 6

using namespace std;

struct Tree{
    double L, R;
    Tree():L(0), R(0){}
};

int n, vis[1 << maxn];
double r, w[maxn], sum[1 << maxn];
vector<Tree> tree[1 << maxn];

void dfs(int subset)
{
    if(vis[subset])
        return;
    vis[subset] = true;

    bool have_child = false;
    for(int left = (subset - 1) & subset; left; left = (left - 1) & subset)
    {
        have_child = true;
        int right = subset ^ left;
        double d1 = sum[right] / sum[subset];
        double d2 = sum[left] / sum[subset];

        dfs(left);
        dfs(right);

        for(int i = 0; i < tree[left].size(); i++)
        {
            for(int j = 0; j < tree[right].size(); j++)
            {
                Tree t;
                t.L = max(tree[left][i].L + d1, tree[right][j].L - d2);
                t.R = max(tree[right][j].R + d2, tree[left][i].R - d1);
                if(t.L + t.R < r)
                    tree[subset].push_back(t);
            }
        }
    }

    if(!have_child)
        tree[subset].push_back(Tree());
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf %d", &r, &n);
        for(int i = 0; i < n; i++)
            scanf("%lf", &w[i]);
        for(int i = 0; i < (1 << n); i++)
        {
            sum[i] = 0;
            tree[i].clear();
            for(int j = 0; j < n; j++)
                if(i & (1 << j))
                    sum[i] += w[j];
        }

        int root = (1 << n) - 1;
        memset(vis, 0, sizeof(vis));
        dfs(root);

        double ans = -1;
        for(int i = 0; i < tree[root].size(); i++)
            ans = max(ans, tree[root][i].L + tree[root][i].R);
        printf("%.10lf\n", ans);
    }
    return 0;
}