//
// Created by 孙启龙 on 2017/3/24.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#define inf 0x7fffffff
using namespace std;
const int maxn=10000+10;
const int M = 1000000+10;

int n,an[maxn];
int vis[M],num[maxn];
vector<int> vec[maxn];

int main()
{
    int ok=0;
    while (scanf("%d",&n)!=EOF && n)
    {
        if (ok) printf("\n");
        ok=1;
        memset(vis,0,sizeof(vis));
        for (int i=0 ;i<maxn ;i++) vec[i].clear();
        int cnt=0,maxSize=0;
        for (int i=1 ;i<=n ;i++)
        {
            scanf("%d",&an[i]);
            vis[ an[i] ]++;
            cnt=max(cnt,vis[ an[i] ]);
            maxSize=max(maxSize,an[i]);
        }
        sort(an+1,an+n+1);
        int c=0;
        for (int i=1 ;i<=n ;i++)
        {
            vec[c].push_back(an[i]);
            c=(c+1)%cnt;
        }
        printf("%d\n",cnt);
        for (int i=0 ;i<cnt ;i++)
        {
            int k=vec[i].size();
            printf("%d",vec[i][0]);
            for (int j=1 ;j<k ;j++)
                printf(" %d",vec[i][j]);
            printf("\n");
        }
    }
    return 0;
}