//
// Created by 孙启龙 on 2017/7/30.
//

#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 500
#define maxm 50

using namespace std;

int n, m;
int s[maxn][maxm], p[maxn][maxm];

inline bool check(int i, int j, int k)
{
    bool a[64];
    memset(a, 0, sizeof(a));
    for(int c = 0; c < n; c++)
        a[s[c][i] * 16 + s[c][j] * 4 + s[c][k]] = 1;
    for(int c = 0; c < n; c++)
        if(a[p[c][i] * 16 + p[c][j] * 4 + p[c][k]])
            return false;
    return true;
}

int main (void)
{
    cin >> n >> m;
    string s1;
    for(int i = 0; i < n; i++)
    {
        cin >> s1;
        for(int j = 0; j < m; j++)
        {
            if(s1[j] == 'A')
                s[i][j] = 0;
            else if (s1[j] == 'C')
                s[i][j] = 1;
            else if (s1[j] == 'G')
                s[i][j] = 2;
            else if (s1[j] == 'T')
                s[i][j] = 3;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cin >> s1;
        for(int j = 0; j < m; j++)
        {
            if(s1[j] == 'A')
                p[i][j] = 0;
            else if (s1[j] == 'C')
                p[i][j] = 1;
            else if (s1[j] == 'G')
                p[i][j] = 2;
            else if (s1[j] == 'T')
                p[i][j] = 3;
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            for(int k = j + 1; k < m; k++)
                if(check(i, j, k))
                    ans++;
    cout << ans << endl;
    return 0;
}