#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#define maxn 110
#define INF 0x3f3f3f3f

using namespace std;


struct Edge {
	int from, to, dist;
	Edge(int from = 0, int to = 0, int dist = 0) :from(from), to(to), dist(dist){}
};

struct HeapNode {
	int d, u;
	HeapNode(int d = 0, int u = 0) :d(d), u(u){}
	bool operator < (const HeapNode& rhs) const {
		return d > rhs.d;
	}
};

struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];    // 是否已永久标号
	int d[maxn];        // s到各个点的距离
	int p[maxn];        // 最短路中的上一条弧

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist) {
		edges.push_back((Edge) ( from, to, dist ));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s) {
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push((HeapNode) (0, s));
		while (!Q.empty()) {
			HeapNode x = Q.top(); Q.pop();
			int u = x.u;
			if (done[u]) continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++) {
				Edge& e = edges[G[u][i]];
				if (e.dist > 0 && d[e.to] > d[u] + e.dist) { // 此处和模板不同，忽略了dist=-1的边。此为删除标记。根据题意和dijkstra算法的前提，正常的边dist>0
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push((HeapNode) ( d[e.to], e.to ));
				}
			}
		}
	}
};

Dijkstra solve;
int n, m, L;
vector<int>gr[maxn][maxn];
int used[maxn][maxn][maxn];
int idx[maxn][maxn];
int sum_single[maxn];

int compute_c()
{
	int ans = 0;
	memset(used, 0, sizeof(used));
	for (int src = 0; src < n; src++)
	{
		solve.dijkstra(src);
		sum_single[src] = 0;
		for (int i = 0; i < n; i++)
		{
			if (i != src)
			{
				int fa = solve.edges[solve.p[i]].from;
				used[src][fa][i] = used[src][i][fa] = 1;
			}
			sum_single[src] += (solve.d[i] == INF ? L: solve.d[i]);
		}
		ans += sum_single[src];
	}
	return ans;
}

int compute_newc(int a, int b)
{
	int ans = 0;
	for (int src = 0; src < n; src++)
	{
		if (!used[src][a][b])
			ans += sum_single[src];
		else
		{
			solve.dijkstra(src);
			for (int i = 0; i < n; i++)
				ans += (solve.d[i] == INF ? L : solve.d[i]);
		}
	}
	return ans;
}

int main (void)
{
	while (scanf("%d %d %d", &n, &m, &L) != EOF)
	{
		solve.init(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				gr[i][j].clear();

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			a--;
			b--;
			gr[a][b].push_back(c);
			gr[b][a].push_back(c);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (!gr[i][j].empty())
				{
					sort(gr[i][j].begin(), gr[i][j].end());
					solve.AddEdge(i, j, gr[i][j][0]);
					idx[i][j] = solve.m - 1;
					solve.AddEdge(j, i, gr[i][j][0]);
					idx[i][j] = solve.m - 1;
				}
			}
		}

		int c = compute_c();
		int c2 = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (!gr[i][j].empty())
				{
					int &e1 = solve.edges[idx[i][j]].dist;
					int &e2 = solve.edges[idx[i][j]].dist;
					if (gr[i][j].size() == 1)
						e1 = e2 = -1;
					else
						e1 = e2 = gr[i][j][1];
					c2 = max(c2, compute_newc(i, j));
					e1 = e2 = gr[i][j][0];
				}
			}
		}

		printf("%d %d", c, c2);
	}
	return 0;
}