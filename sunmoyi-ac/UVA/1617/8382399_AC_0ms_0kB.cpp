//
// Created by 孙启龙 on 2017/3/9.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int n;

bool cmp(pair<int, int>A, pair<int, int>B)
{
    if(A.second != B.second)
        return A.second < B.second;
    return A.first < B.first;
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        vector<pair<int, int> >A;
        int x, y;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            A.push_back(make_pair(x, y));
        }
        sort(A.begin(), A.end(), cmp);

        int ret = 1, right = A[0].second;
        for(int i = 1; i < n; i++)
        {
            if(right != A[i].second)
            {
                if(right < A[i].first)
                {   
                    ret++;
                    right = A[i].second;
                }
                else
                {   
                    right++;
                }
            }
        }
        printf("%d\n", ret - 1);
    }
    return 0;
}