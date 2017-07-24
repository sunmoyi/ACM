//
// Created by 孙启龙 on 2017/4/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
    int id, val;
}a[1005], b[1005];
int n, res1, res2;

bool cmp1(node a, node b)
{
    return a.val < b.val;
}

bool cmp2(node a, node b)
{
    return a.val > b.val;
}

int main (void)
{
    res1 = res2 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        a[i].id = i + 1;
        scanf("%d", &a[i].val);
        res1 += a[i].val;
    }
    for(int i = 0; i < n; i++)
    {
        b[i].id = i + 1;
        scanf("%d", &b[i].val);
        res2 += b[i].val;
    }

    if(res1 > res2)
    {
        sort(a, a + n, cmp1);
        sort(b, b + n, cmp2);
        for(int i = 0; i < n; i++)
            printf("%d %d\n", a[i].id, b[i].id);
    }
    else
    {
        sort(a, a + n, cmp2);
        sort(b, b + n, cmp1);
        for(int i = 0; i < n; i++)
            printf("%d %d\n", a[i].id, b[i].id);
    }
    return 0;
}