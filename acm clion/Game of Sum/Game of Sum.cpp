//
// Created by 孙启龙 on 2017/3/19.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int S[110], A[110], d[110][110], vis[110][110], n;

int dp(int i, int j) {
    if(vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    int m = 0; // 全部取光
    for(int k = i+1; k <= j; k++) m = min(m, dp(k,j));
    for(int k = i; k < j; k++) m = min(m, dp(i,k));
    d[i][j] = S[j]-S[i-1] - m; // 如果i从0开始编号，这里得判断一下是否i==0
    return d[i][j];
}

int main() {
    while(scanf("%d", &n) && n) {
        S[0] = 0;
        for(int i = 1; i <= n; i++) { scanf("%d", &A[i]); S[i]=S[i-1]+A[i]; }
        memset(vis, 0, sizeof(vis)); // 千万不要漏掉
        printf("%d\n", 2*dp(1,n)-S[n]);
    }
    return 0;
}


/*
 * Below is Faster
 *
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int S[110], A[110], d[110][110], vis[110][110], f[110][110], g[110][110], n;

// f[i+1][j] = min{d(i+1,j),d(i+2,j)...,d(j,j)}
// g[i][j-1] = min{d(i,j-1),d(i,j-2)...,d(i,i)}
int main() {
  while(scanf("%d", &n) && n) {
    S[0] = 0;
    for(int i = 1; i <= n; i++)
    {
      scanf("%d", &A[i]);
      S[i]=S[i-1]+A[i];
    }
    for(int i = 1; i <= n; i++)
      f[i][i] = g[i][i] = d[i][i] = A[i]; // 边界
    for(int L = 1; L < n; L++) // 按照L=j-i递增的顺序计算
      for(int i = 1; i+L <= n; i++)
      {
        int j = i+L;
        int m = 0; // m = min{f(i+1,j), g(i,j-1), 0}
        m = min(m, f[i+1][j]);
        m = min(m, g[i][j-1]);
        d[i][j] = S[j]-S[i-1] - m;
        f[i][j] = min(d[i][j], f[i+1][j]); // 递推f和g
        g[i][j] = min(d[i][j], g[i][j-1]);
      }
    printf("%d\n", 2*d[1][n]-S[n]);
  }
  return 0;
}
 *
 *
 * */

