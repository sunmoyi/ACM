//
// Created by 孙启龙 on 2016/11/20.
//

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
    int j, b;
    bool friend operator < (const node&a, const node&b)
    {
        return a.j > b.j;
    }
};

int main (void)
{
    int n, b, j, Case = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        vector<node>v;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &b, &j);
            v.push_back(node{j, b});
        }
        sort(v.begin(), v.end());
        int s = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            s += v[i].b;
            ans = max(ans, s + v[i].j);
        }
        printf("Case %d: %d\n", Case++, ans);
    }
    return 0;
}