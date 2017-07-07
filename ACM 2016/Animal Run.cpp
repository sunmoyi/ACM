#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2000000 + 10;

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
		edges.push_back(Edge ( from, to, dist ));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s) {
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push(HeapNode(0, s));
		while (!Q.empty()) {
			HeapNode x = Q.top(); Q.pop();
			int u = x.u;
			if (done[u]) continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++) {
				Edge& e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push(HeapNode(d[e.to], e.to));
				}
			}
		}
	}
};

