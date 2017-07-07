//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>
#define maxn 320

using namespace std;

int d[maxn][maxn];
int V;
int x[maxn];

void floyed()
{
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main (void)
{
    int M;
    cin >> V >> M;
    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < V; i++)
        d[i][i] = 0;
    while(M--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
            --x[i];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                d[x[i]][x[j]] = d[x[j]][x[i]] = 1;
            }
        }
    }
    floyed();
    int ans = 0x3f3f3f3f;
    for(int i = 0; i < V; i++)
    {
        int sum = 0;
        for(int j = 0; j < V; j++)
            sum += d[i][j];
        ans = min(ans, sum);
    }
    cout << 100 * ans / (V - 1) << endl;
    return 0;
}