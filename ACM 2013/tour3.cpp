#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

double dp[100][100];

struct point
{
	double x, y;
}p[100];


double dis(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main()
{
	int n, i, j;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i<n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		memset(dp, 127, sizeof(dp));
		dp[1][0] = dis(p[0], p[1]);
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<i; j++)
			{
				dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + dis(p[j], p[i + 1]));
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dis(p[i], p[i + 1]));
			}
		}
		double ans = 1000000000;
		for (i = 0; i<n - 1; i++)
			ans = min(ans, dp[n - 1][i] + dis(p[i], p[n - 1]));
		printf("%.2lf\n", ans);
	}
	return 0;
}