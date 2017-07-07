#include<cstdio>  
#include<string>  
#include<cmath>  
#include<algorithm>  

using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
const int INF = 1e7 + 10;

double dp[maxn][maxn];
int x[maxn], y[maxn], z[maxn], r[maxn];

int main()
{
	int n;
	int kase = 0;
	while (scanf("%d", &n) && n + 1)
	{
		for (int i = 1; i <= n + 2; i++)
			for (int j = 1; j <= n + 2; j++)
				if (i == j) 
					dp[i][j] = 0;
				else 
					dp[i][j] = INF;
		for (int i = 1; i <= n; i++) 
			scanf("%d %d %d %d", x + i, y + i, z + i, r + i);
		for (int i = n + 1; i <= n + 2; i++)
			scanf("%d %d %d", x + i, y + i, z + i), r[i] = 0;
		
		for (int i = 1; i <= n + 2; i++)
		{
			for (int j = i + 1; j <= n + 2; j++)
			{
				double dist = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j]));
				if (dist > r[i] + r[j])
				{
					dp[i][j] = dp[j][i] = dist - (double)(r[i] + r[j]);
				}
				else 
					dp[i][j] = dp[j][i] = 0;
			}
		}
		for (int k = 1; k <= n + 2; k++)
			for (int i = 1; i <= n + 2; i++)
				for (int j = 1; j <= n + 2; j++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		printf("Cheese %d: Travel time = %.0lf sec\n", ++kase, dp[n + 1][n + 2] * 10.0);
	}
}