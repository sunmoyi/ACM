//
// Created by 孙启龙 on 2017/3/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 5010

using namespace std;

int T, n, temp, pos;
int a[maxn], b[maxn], maxm[maxn][maxn];
vector<int>vec[maxn];

bool judge(int x[])
{
    for(int i = 0; i < n; i++)
    {
        temp = x[i];
        maxm[i][i] = x[i];
        for(int j = i + 1; j < n; ++j)
        {
            if(x[j] > temp)
            {
                maxm[i][j] = x[j];
                temp = x[j];
            }
            else
                maxm[i][j] = maxm[i][j - 1];
        }
    }
    for(int i = 0; i < n; i++)
    {
        vec[i].clear();
        for(int j = i + 1; j < n; j++)
            if(x[j] > x[i])
                vec[i].push_back(x[j]);
        sort(vec[i].begin(), vec[i].end());
    }

    for (int i = 0; i < n; ++i)
        for (int j = i + 2; j < n; ++j)
            if (x[j] < x[i])
                if (maxm[i][j - 1] > x[j])
                {
                    pos = lower_bound(vec[j].begin(), vec[j].end(), x[i]) - vec[j].begin();
                    if(pos != vec[j].size())
                        if(vec[j][pos] < maxm[i][j - 1])
                            return true;
                }
    return false;
}

int main (void)
{
    scanf("%d", &T);
    for(int C = 0; C < T; C++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            b[n - i - 1] = a[i];
        }
        if(judge(a) || judge(b))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}