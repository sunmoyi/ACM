#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 50
#define PI acos(-1.0)

using namespace std;

int n, m, i, j, k, x;
double p[maxn];
double dp[maxn][maxn][maxn];

double cal(double p1, double p2)
{
	double d = PI * (p1 - p2);
	return 2 * sin(d);
}

double area(double p1, double p2, double p3)
{
	double a = cal(p1, p2);
	double b = cal(p2, p3);
	double c = cal(p3, p1);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		double ans = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			scanf("%lf", &p[i]);
		//printf("1\n");

		for (int x = 1; x <= n; x++)
		{
			int t = min(x, m);
			for (int i = 3; i <= t; i++)
			{
				for (int j = 1; j <= x; j++)
				{
					for (int k = j + 1; k < x; k++)
					{
						double s = area(p[x], p[k], p[j]);
						dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][k] + s);
						if (i == m)
							ans = max(ans, dp[i][j][x]);
					}
				}
			}
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}