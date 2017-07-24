//
// Created by 孙启龙 on 2017/4/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
#include<iostream>

using namespace std;

map<string, priority_queue<int> >p;
string jud[1000010], temp;
int val;

int main (void)
{
    int n, k, now, x;
    long long ans;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        cin >> jud[i];
        cin >> val;
        p[jud[i]].push(val);
    }
    x = 0, ans = 0;
    for(int i = 1; i <= n; i++)
    {
        temp = jud[i];
        reverse(temp.begin(), temp.end());
        if(temp != jud[i])
        {
            while(p[temp].empty() == 0 && p[jud[i]].empty() == 0 && p[temp].top() + p[jud[i]].top() > 0)
            {
                ans += p[temp].top() + p[jud[i]].top();
                p[temp].pop();
                p[jud[i]].pop();
            }
        }
        else
        {
            while(p[temp].size() > 1)
            {
                now = p[temp].top();
                p[temp].pop();
                if(p[temp].top() + now > 0)
                {
                    ans += p[temp].top() + now;
                    x = min(x, p[temp].top());
                    p[temp].pop();
                }
                else
                {
                    p[temp].push(now);
                    break;
                }
            }
        }
    }
    x = -x;
    for(int i = 1; i <= n; i++)
    {
        temp = jud[i];
        reverse(temp.begin(), temp.end());
        if(temp == jud[i] && p[temp].empty() == 0)
            x = max(x, p[temp].top());
    }
    printf("%lld\n", ans + x);
    return 0;
}