#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 1000000000;
const int maxn = 4000 + 10;

struct Edge {
	int from, to, dist, val;
	Edge(int from = 0, int to = 0, int dist = 0, int val = 0) :from(from), to(to), dist(dist), val(val){}
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
	bool done[maxn];    // �Ƿ������ñ��
	int d[maxn];        // s��������ľ���
	int p[maxn];        // ���·�е���һ����

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist, int val) {
		edges.push_back(Edge(from, to, dist, val ));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s) {
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push(HeapNode( 0, s ));
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
					Q.push(HeapNode( d[e.to], e.to ));
				}
			}
		}
	}

	vector<int> GetShortestPath(int s, int t) {
		vector<int> path;
		while (t != s) {
			path.push_back(edges[p[t]].val);
			t = edges[p[t]].from;
		}
		reverse(path.begin(), path.end());
		return path;
	}
};

#include<map>
#define maxn 110

int n_city;
map<int, int>city_id;
int cost[maxn];
vector<int>cities[maxn], iti;
Dijkstra solve;

int ID(int city) 
{
	if (city_id.count(city)) 
		return city_id[city];
	city_id[city] = n_city++;
	return n_city - 1;
}

int ID(int visited, int cur) 
{ 
	return (visited - 1) * n_city + cur; 
}

int main(void)
{
	int NT, NI, x, len, Case = 0;
	while(scanf("%d", &NT) != EOF && NT)
	{
		n_city = 0;
		city_id.clear();
		for (int i = 0; i < NT; i++)
		{
			cities[i].clear();
			scanf("%d%d", &cost[i], &len);
			while (len--) 
			{ 
				scanf("%d", &x); 
				cities[i].push_back(ID(x)); 
			}
		}
		scanf("%d", &NI);
		Case++;
		for (int trip = 1; trip <= NI; trip++)
		{
			iti.clear();
			scanf("%d", &len);
			for (int i = 0; i < len; i++)
			{
				scanf("%d", &x);
				iti.push_back(ID(x));
			}

			solve.init(n_city * len);
			for (int ticket = 0; ticket < NT; ticket++) 
			{
				for (int visited = 1; visited < len; visited++)
				{
					int cur = cities[ticket][0]; // ��ǰ״̬Ϊ(visited, cur)
					int next = visited;          // ��һ����Ҫ���ʵĳ�����iti�е��±�
					for (int leg = 1; leg < cities[ticket].size(); leg++) 
					{ // ʹ��ǰleg��
						if (cities[ticket][leg] == iti[next]) 
							next++; // �г��϶ྭ��һ������
						solve.AddEdge(ID(visited, cur), 
							ID(next, cities[ticket][leg]),cost[ticket], ticket + 1);
						if (next == len) 
							break; // �г̵��Ѿ�����
					}
				}
			}

			int src = ID(1, iti[0]), dest = ID(len, iti[len - 1]);
			solve.dijkstra(src);
			printf("Case %d, Trip %d: Cost = %d\n", Case, trip, solve.d[dest]);
			printf("  Tickets used:");
			vector<int> path = solve.GetShortestPath(src, dest);
			for (int i = 0; i < path.size(); i++)
				printf(" %d", path[i]);
			printf("\n");
		}
	}
	return 0;
}