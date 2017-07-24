//
// Created by 孙启龙 on 2017/5/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#define maxn 1010

using namespace std;

string a[maxn], b[maxn];

int main (void)
{
    int n, m;
    while(cin >> n >> m)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];

        int common = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i] == b[j])
                    ++common;

        if(common & 1)
        {
            if(n > m - 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if(n > m)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}