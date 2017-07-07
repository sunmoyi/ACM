#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 110
#define INF 0x3f3f3f3f
#define esp 1e-6

using namespace std;

int ans;
int n, m;
double x[maxn], y[maxn];
double dis[maxn][maxn];
bool vis[maxn];

int zero(double x, double y)
{
	if (abs(x - y) <= esp)
		return 0;
	if (x > y)
		return 1;
	else
		return -1;
}

int check(int t, int r)
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (zero(dis[t][i], r) < 0)
			ans++;
		else if (zero(dis[t][i], r) == 0)
			return -1;
	}
	return ans;
}
int main (void)
{
	scanf("%d", &ans);
	while (ans--)
	{
		memset(vis, true, sizeof(vis));
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf", &x[i], &y[i]);
		if (n < m)
		{
			printf("-1\n");
			continue;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			}
		}

		bool flag = false;
		int x;
		for (int i = 1; i <= 3000; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (vis[j] == true)
				{
					x = check(j, i);
					if (x == m)
					{
						printf("%d\n", i);
						flag = true;
						break;
					}
					else if (x > m)
						vis[j] = false;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (!flag)
			printf("-1\n");
	}
	return 0;
}