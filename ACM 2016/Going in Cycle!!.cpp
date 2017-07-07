#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

struct Edge {
	int from, to;
	double dist;
	Edge(int from = 0, int to = 0, double dist = 0) :from(from), to(to), dist(dist){}
};

struct bellman_Ford {
	int n, m;
	vector<Edge>edges;
	vector<int>G[maxn];
	bool inqueue[maxn];
	double d[maxn];
	int p[maxn];
	int cnt[maxn];

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void addedge(int from, int to, double dist)
	{
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m - 1 );
	}

	bool negativeCycle() 
	{

		queue<int>Q;
		memset(inqueue, 0, sizeof(inqueue));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			d[i] = INF;
			inqueue[0] = true;
			Q.push(i);
		}

		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inqueue[u] = false;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					if (!inqueue[e.to])
					{
						inqueue[e.to] = true;
						Q.push(e.to);
						if (++cnt[e.to] > n)
							return true;
					}
				}
			}
		}
		return false;
	}
};

bellman_Ford solve;

bool test(double x)
{
	for (int i = 0; i < solve.m; i++)
		solve.edges[i].dist -= x;
	bool ret = solve.negativeCycle();
	for (int i = 0; i < solve.m; i++)
		solve.edges[i].dist += x;
	return ret;
}

int main (void)
{
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; Case++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		solve.init(n);
		int ub = 0;
		while (m--)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			ub = max(w, ub);
			solve.addedge(u, v, w);
		}
		printf("Case #%d: ", Case);
		if (!test(ub + 1))
			printf("No cycle found\n");
		else
		{
			double L = 0, R = ub;
			while (R - L > 1e-3)
			{
				double M = (L + R) / 2;
				if (test(M))
					R = M;
				else
					L = M;
			}
			printf("%.2lf\n", L);
		}
	}
	return 0;
}