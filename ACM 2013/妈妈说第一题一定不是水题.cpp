#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v;
	int len;
	int dis;
	node(int v = 0, int len = 0, int dis = 0) : v(v), len(len), dis(dis) {}
	friend bool operator < (const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int mindist[maxn][3];
int n, m, mind, minp;
vector<node>G[maxn];

void init(void)
{
	for(int i =0; i < maxn; i++)
	{
		inqueue[i] = false;
		mindist[i][1] = INF;
		G[i].clear();
		mindist[i][2] = INF;
	}
}

void Dijkstra(int s)
{
	mindist[s][1] = 0;
	mindist[s][2] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		Q.push(G[s][i]);
		inqueue[vex] = true;
		if (mindist[vex][1] > G[s][i].len)
		{
			mindist[vex][1] = G[s][i].len;
			mindist[vex][2] = G[s][i].dis;
		}
		else if (mindist[vex][1] == G[s][i].len && mindist[vex][2] > G[s][i].dis)
		{
			mindist[vex][1] = G[s][i].len;
			mindist[vex][2] = G[s][i].dis;
		}
	}
	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		inqueue[now.v] = false;
		for(int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			int len = G[now.v][i].len;
			int pri = G[now.v][i].dis;
			if ((len + mindist[now.v][1] < mindist[vex][1]) || ((len + mindist[now.v][1] == mindist[vex][1]) && (pri + mindist[now.v][2] < mindist[vex][2])))
			{
				mindist[vex][1] = len + mindist[now.v][1];
				mindist[vex][2] = pri + mindist[now.v][2];
				if (!inqueue[vex])
				{
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
}

int main (void)
{
	int a, b, len, pri;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		init();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d %d", &a, &b, &len, &pri);
			G[a].push_back(node(b, len, pri));
			G[b].push_back(node(a, len, pri));
		}
		int S, T;
		scanf("%d %d", &S, &T);
		Dijkstra(S);
		printf("%d %d\n", mindist[T][1], mindist[T][2]);
	}
	return 0;
}