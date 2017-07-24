//
// Created by 孙启龙 on 2017/3/29.
//

#include<iostream>
#include<algorithm>
#include<string>
#define maxn 20010

using namespace std;

int pa[maxn], d[maxn];

int findset(int x)
{
    if(pa[x] == x)
        return x;
    else
    {
        int fa = findset(pa[x]);
        d[x] += d[pa[x]];
        return pa[x] = fa;
    }
}

int main (void)
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, u, v;
        string cmd;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            pa[i] = i;
            d[i] = 0;
        }
        while(cin >> cmd && cmd[0] != 'O')
        {
            if(cmd[0] == 'E')
            {
                cin >> u;
                findset(u);
                cout << d[u] << endl;
            }
            if(cmd[0] == 'I')
            {
                cin >> u >> v;
                pa[u] = v;
                d[u] = abs(u - v) % 1000;
            }
        }
    }
    return 0;
}