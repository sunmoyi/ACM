#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define Min(x, y)(x < y? x :y)
using namespace std;
const int INF = 0xfffffff;
const int maxn = 105;
struct node {
	int v;
	int len;
	node(int v = 0, int len = 0) :v(v), len(len){}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int mindist[maxn];
int cnt[maxn];
int n, m;
vector<node>G[maxn];

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		inqueue[i] = false;
		mindist[i] = INF;
		cnt[i] = 0;
		G[i].clear();
	}
}

int Dijkstra(int s, int t)
{
	mindist[s] = 0;
	cnt[s]++;
	priority_queue<node>Q;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		Q.push(G[s][i]);
		inqueue[vex] = true;
		cnt[vex]++;
		mindist[vex] = min(G[s][i].len, mindist[vex]);
	}
	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		inqueue[now.v] = false;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			int len = G[now.v][i].len;
			if (len + mindist[now.v] < mindist[vex])
			{
				mindist[vex] = len + mindist[now.v];
				if (!inqueue[vex])
				{
					cnt[vex]++;
					if (cnt[vex] == n)
						return INF;
					inqueue[vex] = true;
					Q.push(node(G[now.v][i]));
				}
			}
		}
	}
	return mindist[t];
}

int main(void)
{
	while(scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		init();
		int a, b, len;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		int ans = Dijkstra(1, n);
		printf("%d\n", ans);
	}
	return 0;
}