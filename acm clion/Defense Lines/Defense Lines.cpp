//
// Created by 孙启龙 on 2017/2/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 200010

using namespace std;

int n, a[maxn], f[maxn], g[maxn];

struct Candidate{
    int a, g;
    Candidate(int a, int g):a(a), g(g){}
    bool operator < (const Candidate &rhs) const {
        return a < rhs.a;
    }
};

set<Candidate>s;

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if(n == 1)
        {
            printf("1\n");
            continue;
        }

        g[0] = 1;
        for(int i = 1; i < n; i++)
        {
            if(a[i - 1] < a[i])
                g[i] = g[i - 1] + 1;
            else
                g[i] = 1;
        }

        f[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(a[i] < a[i + 1])
                f[i] = f[i + 1] + 1;
            else
                f[i] = 1;
        }

        s.clear();
        s.insert(Candidate(a[0], g[0]));
        int ans = 1;
        for(int i = 1; i < n; i++)
        {
            Candidate c(a[i], g[i]);
            set<Candidate>::iterator it = s.lower_bound(c);
            bool keep = true;
            if(it != s.begin())
            {
                Candidate last = *(--it);
                int len = f[i] + last.g;
                ans = max(ans, len);
                if(c.g <= last.g)
                    keep = false;
            }

            if(keep)
            {
                s.erase(c);
                s.insert(c);
                it = s.find(c);
                it++;
                while(it != s.end() && it->a > c.a && it->g <= c.g)
                    s.erase(it++);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}