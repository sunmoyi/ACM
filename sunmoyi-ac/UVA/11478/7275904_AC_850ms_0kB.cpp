#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 510
#define maxm 2700
#define INF 0x3f3f3f3f

using namespace std;

struct Edge {
	int to, dist;
	Edge(int to = 0, int dist = 0) :to(to), dist(dist){}
};

struct BellmanFord {
	int n, m;
	Edge edges[maxm];
	int head[maxn];
	int next[maxm];
	bool inqueue[maxn];
	int d[maxn];
	int cnt[maxn];

	void init(int n)
	{
		this->n = n;
		m = 0;
		memset(head, -1, sizeof(head));
	}

	void addedge(int from, int to, int dist)
	{
		next[m] = head[from];
		head[from] = m;
		edges[m++] = Edge(to, dist);
	}

	bool negativeCycle()
	{
		queue<int>Q;
		memset(inqueue, false, sizeof(inqueue));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			d[i] = INF;
			Q.push(i);
		}

		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inqueue[u] = false;
			for (int i = head[u]; i != -1; i = next[i])
			{
				Edge &e = edges[i];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					if (!inqueue[e.to])
					{
						Q.push(e.to);
						inqueue[e.to] = true;
						if (++cnt[e.to] > n)
							return true;
					}
				}
			}
		}
		return false;
	}
};

BellmanFord solve;

bool test(int x)
{
	for (int i = 0; i < solve.m; i++)
		solve.edges[i].dist -= x;
	bool ret = solve.negativeCycle();
	for (int i = 0; i < solve.m; i++)
		solve.edges[i].dist += x;
	return !ret;
}

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		solve.init(n);
		int ub = 0;
		while (m--)
		{
			int u, v, d;
			scanf("%d %d %d", &u, &v, &d);
			ub = max(ub, d);
			solve.addedge(u - 1, v - 1, d);
		}

		if (test(ub + 1))
			printf("Infinite\n");
		else if (!test(1))
			printf("No Solution\n");
		else
		{
			int L = 2, R = ub, ans = 1;
			while (L <= R)
			{
				int M = (L + R) / 2;
				if (test(M))
				{
					ans = M;
					L = M + 1;
				}
				else
					R = M - 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}