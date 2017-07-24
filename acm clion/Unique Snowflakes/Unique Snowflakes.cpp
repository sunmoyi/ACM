//
// Created by 孙启龙 on 2017/2/14.
//
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 1000010

using namespace std;

int A[maxn];

int main (void)
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &A[i]);

        set<int>s;
        int L = 0, R = 0, ans = 0;
        while(R < n)
        {
            while(R < n && !s.count(A[R]))
                s.insert(A[R++]);
            ans = max(ans, R - L);
            s.erase(A[L++]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 1000010

using namespace std;

int A[maxn], last[maxn];
map<int, int>cur;

int main (void)
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        cur.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
            if(!cur.count(A[i]))
                last[i] = -1;
            else
                last[i] = cur[A[i]];
            cur[A[i]] = i;
        }

        int L = 0 , R = 0, ans = 0;
        while(R < n)
        {
            while(R < n && last[R] < L)
                R++;
            ans = max(ans, R - L);
            L++;
        }
        printf("%d\n", ans);
    }
    return 0;
}