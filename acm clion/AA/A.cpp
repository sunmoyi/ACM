//
// Created by 孙启龙 on 2017/4/23.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000

using namespace std;

struct node{
    int val, pos;
}num[maxn];
int n;

bool cmp(node &a, node &b)
{
    if(a.val == b.val)
        return a.pos < b.pos;
    return a.val < b.val;
}

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i].val);
            num[i].pos = i;
        }

        sort(num + 1, num + n + 1, cmp);

        int minn = num[1].pos;
        int ans = 0;
        for(int i = 2; i <= n; i++)
        {
            int temp = num[i].pos - minn;
            if(temp > 0)
                ans = max(ans ,temp);
            minn = min(minn, num[i].pos);
        }
        printf("%d\n", ans);
    }
    return 0;
}
