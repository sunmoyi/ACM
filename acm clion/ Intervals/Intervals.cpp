//
// Created by 孙启龙 on 2017/4/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int T, n;
typedef pair<int, pair<int, int> >P;
P p[5];
P num[50010];
int ans[50010];

bool cmpleft(P a, P b)
{
    return a.second.first < b.second.first;
}

bool cmprightdown(P a, P b)
{
    return a.second.second > b.second.second;
}

bool cmprightup(P a, P b)
{
    return a.second.second < b.second.second;
}

int main (void)
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &num[i].second.first, &num[i].second.second), num[i].first = i;

        sort(num + 1, num + n + 1, cmpleft);

        int ansnum = 0, arraynum = 0;
        for(int i = 1; i <= n; i++)
        {
            if(arraynum != 0)
            {
                sort(p, p + arraynum, cmprightdown);
                if(p[arraynum - 1].second.second < num[i].second.first)
                    arraynum--;
            }
            p[arraynum++] = num[i];
            if(arraynum == 3)
            {
                sort(p, p + arraynum, cmprightup);
                ans[ansnum++] = p[2].first;
                arraynum--;
            }
        }
        printf("%d\n", ansnum);
        sort(ans, ans + ansnum);
        for(int i = 0; i < ansnum - 1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[ansnum - 1]);
    }
    return 0;
}