#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f
#define esp 1e-6
#define maxn 55
using namespace std;

struct Point {
	double x, y;

}point[maxn];
double dp[maxn][maxn];
int n;

double area(Point a, Point b, Point c)
{
	return fabs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2.0;
}

bool judge(int a, int b, int c)
{
	for (int i = 1; i <= n; i++)
	{
		if (i == a || i == b || i == c)
			continue;
		double s = area(point[i], point[a], point[b]) + area(point[i], point[b], point[c]) + area(point[i], point[c], point[a]);
		if (fabs(s - area(point[a], point[b], point[c])) < esp)
			return true;
	}
	return false;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf", &point[i].x, &point[i].y);

		for (int len = 2; len < n; len++)
		{
			for (int i = 1; i + len <= n; i++)
			{
				int j = i + len;
				dp[i][j] = INF;
				for (int k = i + 1; k < j; k++)
				{
					if (judge(i, k, j))
						continue;
					dp[i][j] = min(dp[i][j], max(max(dp[i][k], dp[k][j]), area(point[i], point[k], point[j])));
				}
			}
		}
		printf("%.1lf\n", dp[1][n]);
	}
	return 0;
}