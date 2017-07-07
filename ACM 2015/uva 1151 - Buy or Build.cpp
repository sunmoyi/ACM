#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1005

using namespace std;

struct point {
	int x;
	int y;
}pp[maxn];

struct edge {
	int from;
	int to;
	int dist;
	edge(int from = 0, int to = 0, int dist = 0) :from(from), to(to), dist(dist) {}
	bool friend operator < (const edge & a, const edge&b)
	{
		return a.dist < b.dist;
	}
}l[maxn*maxn], ll[maxn * 2];

int n, q, m, mm;
int father[maxn];
vector<int>G[10];
int c[10];

int distance(point a, point b)
{
	return (a.x - b.x) *(a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];
	return far;
}

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	else
		father[x] = y;
	return true;
}

int kruskal(int a)
{
	if (a == 1)
	{
		int ans = 0;
		int num = 0;
		for (int i = 0; i < m && num < n - 1; i++)
		{
			if (unoin(l[i].from, l[i].to))
			{
				num++;
				ans += l[i].dist;
				ll[mm++] = l[i];
			}
		}
		return ans;
	}
	else
	{
		int ans = 0;
		int num = 0;
		for (int i = 0; i < mm; i++)
		{
			if (unoin(ll[i].from, ll[i].to))
			{
				num++;
				ans += ll[i].dist;
			}
		}
		return ans;
	}
}

void solve()
{
	for (int i = 0; i <= n; i++)
		father[i] = i;
	int ans = kruskal(1);
	for (int s = 1; s < (1 << q); s++)
	{
		int cost = 0;
		for (int tt = 0; tt <= n; tt++)
			father[tt] = tt;
		for (int j = 0; j < q; j++)
		{
			if (!((s >> j) & 1))
				continue;
			cost += c[j];
			for (int k = 0; k < G[j].size(); k++)
			{
				unoin(G[j][k], G[j][0]);
			}
		}
		ans = min(ans, cost + kruskal(0));
	}
	printf("%d\n", ans);
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		mm = 0;
		scanf("%d %d", &n, &q);
		for (int i = 0; i < 10; i++)
			G[i].clear();
		for (int i = 0; i < q; i++)
		{
			int cnt, a;
			scanf("%d %d", &cnt, &c[i]);
			for (int j = 0; j < cnt; j++)
			{
				scanf("%d", &a);
				G[i].push_back(a);
			}
		}
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &pp[i].x, &pp[i].y);
		m = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				l[m].from = i;
				l[m].to = j;
				l[m++].dist = distance(pp[i], pp[j]);
			}
		}
		sort(l, l + m);
		solve();
		if (t)
			printf("\n");
	}
	return 0;
}