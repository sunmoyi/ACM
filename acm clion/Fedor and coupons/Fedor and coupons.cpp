//
// Created by 孙启龙 on 2017/1/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 3000010

using namespace std;

struct node{
    int left, right, id;
}a[maxn];

bool cmp(node x, node y)
{
    return x.left < y.left;
}

int main (void)
{
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &a[i].left, &a[i].right);
            a[i].id = i + 1;
        }
        priority_queue<int, vector<int>, greater<int> >que;
        sort(a, a + n, cmp);
        int ans = 0, L = 0;
        for(int i = 0; i < n; i++)
        {
            que.push(a[i].right);
            if(que.size() > k)
                que.pop();
            int len = que.top() - a[i].left + 1;
            if(ans < len && que.size() == k)
            {
                ans = len;
                L = a[i].left;
            }
        }
        printf("%d\n", ans);
        if(ans == 0)
        {
            printf("1");
            for(int i = 2; i <= k; i++)
                printf(" %d", i);
        }
        else
        {
            for(int i = 0; i < n && k; i++)
            {
                if(L >= a[i].left && ans + L - 1 <= a[i].right)
                {
                    if(k >= 1)
                        printf("%d ", a[i].id);
                    else
                        printf("%d", a[i].id);
                    k--;
                }
            }
        }
        printf("\n");
    }
    return 0;
}