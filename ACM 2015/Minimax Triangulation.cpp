/*#include<cstdio>  
#include<iostream>  
#include<algorithm>  
#include<cstring>  
#include<cmath>  
using namespace std;
#define inf 0x3f3f3f3f  
const double esp = 1e-6;
int n;
struct point
{
	double x, y;

}poi[55];
double dp[55][55];

double area(point a, point b, point c)
{
	return fabs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2.0;
}

bool judge(int a, int b, int c)
{
	for (int i = 1; i <= n; i++)
	{
		if (i == a || i == b || i == c) 
			continue;
		double s = area(poi[i], poi[a], poi[b]) + area(poi[i], poi[b], poi[c]) + area(poi[i], poi[c], poi[a]);
		if (fabs(s - area(poi[a], poi[b], poi[c])) < esp) 
			return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &poi[i].x, &poi[i].y);
		}
		for (int l = 2; l < n; l++)
			for (int p = 1; p + l <= n; p++)
			{
				dp[p][p + l] = inf;
				for (int k = p + 1; k < p + l; k++)
				{
					if (judge(p, k, p + l)) 
						continue;
					dp[p][p + l] = min(dp[p][p + l], max(max(dp[p][k], dp[k][p + l]), area(poi[p], poi[k], poi[p + l])));
				}
			}
		printf("%.1f\n", dp[1][n]);
	}
	return 0;
}*/