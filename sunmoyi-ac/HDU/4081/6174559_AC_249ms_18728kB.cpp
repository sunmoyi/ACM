#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1010
#define INF 0xfffffff

using namespace std;

struct node {
	double x;
	double y;
	double len;
}pos[maxn];
bool vis[maxn];
double lowc[maxn];
int pre[maxn];
double maxx[maxn][maxn];
bool used[maxn][maxn];
double ans;
double cost[maxn][maxn];
int n;

double dis(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double prim(int n)
{
	ans = 0;
	memset(vis, false, sizeof(vis));
	memset(maxx, 0, sizeof(maxx));
	memset(used, false, sizeof(used));
	vis[0] = true;
	pre[0] = -1;
	for (int i = 1; i < n; i++)
	{
		lowc[i] = cost[0][i];
		pre[i] = 0;
	}
	lowc[0] = 0;
	for (int i = 1; i < n; i++)
	{
		double minc = INF;
		int p = -1;
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && minc > lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		}
		if (minc == INF)
			return -1;
		ans += minc;
		vis[p] = true;
		used[p][pre[p]] = used[pre[p]][p] = true;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] && j != p)
				maxx[j][p] = maxx[p][j] = max(maxx[j][pre[p]], lowc[p]);
			if (!vis[j] && lowc[j] > cost[p][j])
			{
				lowc[j] = cost[p][j];
				pre[j] = p;
			}
		}
	}
	return ans;
}

int main(void)
{
	int T;
	scanf_s("%d", &T);
	while (T--)
	{
		scanf_s("%d", &n);
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < n; i++)
			scanf_s("%lf %lf %lf", &pos[i].x, &pos[i].y, &pos[i].len);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					cost[i][j] = dis(pos[i], pos[j]);
				}
			}
		}
		prim(n);
	//	printf("%lf\n", ans);
		double maxxx = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					if (used[i][j])
						maxxx = max(maxxx, (pos[i].len + pos[j].len) / (ans - cost[i][j]));
					else
						maxxx = max(maxxx, (pos[i].len + pos[j].len) / (ans - maxx[i][j]));
				}
			}
		}
		printf("%.2lf\n", maxxx);
	}
	return 0;
}