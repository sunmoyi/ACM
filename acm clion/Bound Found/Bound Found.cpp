//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define abs(x) ((x) > 0? (x): (-(x)))
#define INF 0x3f3f3f3f

using namespace std;

pair<int, int>p[100010];
int n, m, k;

void solve(int k)
{
    int l = 0, r = 1, al = l, ar = r, av = 0, minn = INF;
    while(l <= n && r <= n)
    {
        int temp = p[r].first - p[l].first;
        if(abs(temp - k) < minn)
        {
            minn = abs(temp - k);
            ar = p[r].second;
            al = p[l].second;
            av = temp;
        }
        if(temp > k)
            l++;
        else if (temp < k)
            r++;
        else
            break;
        if(r == l)
            r++;
    }
    if(al > ar)
        swap(al, ar);
    printf("%d %d %d\n", av, al + 1, ar);
}

int main (void)
{
    while(scanf("%d %d", &n, &m) != EOF && (n + m))
    {
        p[0] = make_pair(0, 0);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i].first);
            p[i].first += p[i - 1].first;
            p[i].second = i;
        }
        sort(p, p + n + 1);
        while(m--)
        {
            scanf("%d", &k);
            solve(k);
        }
    }
    return 0;
}