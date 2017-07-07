/*#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int x[10005], y[10005], fa[1000005];
double fun(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}
int find(int x)
{
	int k, j, r;
	r = x;
	while (r != fa[r])
		r = fa[r];
	k = x;
	while (k != r)
	{
		j = fa[k];
		fa[k] = r;
		k = j;
	}
	return r;
}
int main()
{
	int t, n, i, j, k;
	double len;
	scanf("%d", &t);
	while (t--)
	{
		pair<int, int> pa;
		pair< double, pair<int, int> > p[10005];
		k = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d %d", &x[i], &y[i]);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (i == j) continue;
				len = fun(x[i], y[i], x[j], y[j]);
				if (len >= 10 && len <= 1000)
				{
					pa = make_pair(i, j);
					p[k++] = make_pair(len, pa);
				}
			}
		sort(p, p + k);
		for (i = 0; i <= n; i++)
			fa[i] = i;
		int a, b, ans = 0;
		double cnt = 0;
		for (i = 0; i < k; i++)
		{
			a = find(p[i].second.first);
			b = find(p[i].second.second);
			if (a != b)
			{
				fa[a] = b;
				cnt += p[i].first;
				ans++;
			}
		}
		if (ans == n - 1)
			printf("%.1lf\n", cnt * 100);
		else
			printf("oh!\n");
	}
	return 0;
}*/


#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;

struct Node {
	double x, y;
}node[maxn];

double cost[maxn][maxn];
int vis[maxn];
double lowc[maxn];

double distance(Node a, Node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double prim(int n)
{
	int  p;
	double minc, res = 0;
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	for (int i = 1; i < n; i++)
		lowc[i] = cost[0][i];
	for (int i = 1; i < n; i++)
	{
		minc = INF;
		p = -1;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == 0 && minc > lowc[j])
			{
				minc = lowc[j];
				p = j;
			}
		}
		if (minc == INF)
			return -1;
		res += minc;
		vis[p] = 1;
		for (int j = 0; j < n; j++)
			if (vis[j] == 0 && lowc[j] > cost[p][j] && cost[p][j] != INF)
				lowc[j] = cost[p][j];
	}
	return res;
}

int main(void)
{
	int n, T;
	scanf("%d", &T);
	while (T--)	
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &node[i].x, &node[i].y);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					cost[i][j] = 0;
				else
				{
					cost[i][j] = distance(node[i], node[j]);
					if (cost[i][j] > 1000 || cost[i][j] < 10)
						cost[i][j] = INF;
				}
			}
		}
		double ans = prim(n);
		if (ans == -1)
			printf("oh!\n");
		else
			printf("%.1lf\n", (ans * 100));
	}
	return 0;
}
