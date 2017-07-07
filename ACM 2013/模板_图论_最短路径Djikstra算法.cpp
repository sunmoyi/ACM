#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
#define INF 0xfffffff
using namespace std;

struct node{
	int v;
	int len;
	node(int v = 0, int len = 0) : v(v), len(len){}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
vector<node>G[maxn];
int mindist[maxn];
int V, E;
bool inqueue[maxn];

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		G[i].clear();
		inqueue[i] = false;
		mindist[i] = INF;
	}
}

int Dijkstra(int s, int t)
{
	mindist[s] = 0;
	queue<node>Q;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		Q.push(G[s][i]);
		mindist[vex] = min(G[s][i].len, mindist[vex]);
		inqueue[vex] = true;
	}
	while (!Q.empty())
	{
		node now = Q.front();
		Q.pop();
		inqueue[now.v] = false;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			int len = G[now.v][i].len;
			if (len + mindist[now.v] < mindist[vex])
			{
				mindist[vex] = mindist[now.v] + len;
				if (!inqueue[vex])
				{
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
	return mindist[t];
}

int main(void)
{
	int a, b, len;
	int S, T;
	while (scanf("%d %d", &V, &E) != EOF)
	{
		init();
		for (int i = 1; i <= V; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
		}
		scanf("%d %d", &S, &T);
		int ans = Dijkstra(S, T);
		printf("%d\n", ans);
	}
	return 0;
}