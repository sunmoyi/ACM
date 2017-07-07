#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define maxn 1005
#define INF 1000000
using namespace std;

int n, k;
double a[maxn];

bool cheak(double gg)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		num += int(a[i] / gg);
	}
	return num >= k;
}

double solve()
{
	double l = 0, u = INF;
	for (int i = 1; i < 100; i++)
	{
		double mid = (l + u) / 2;
		if (cheak(mid))
			l = mid;
		else
			u = mid;
	}
	return (u * 100) / 100;
}

int main(void)
{
	while (scanf("%d %d", &n, &k) != EOF)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &a[i]);
		}
		double ans = solve();
		printf("%.2lf\n", ans);
	}
	return 0;
}