#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 0xfffffff
#define maxn 1005
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
int V, E;
bool inqueue[maxn];
int cnt[maxn];
int mindist[maxn];

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		mindist[i] = INF;
		G[i].clear();
		inqueue[i] = false;
		cnt[i] = 0;
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
		cnt[vex]++;
		mindist[vex] = min(G[s][i].len, mindist[vex]);
		inqueue[vex] = 1;
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
				mindist[vex] = mindist[now.v] + len;
				if (!inqueue[vex])
				{
					cnt[vex]++;
					if (cnt[vex] == V)
						return INF;
					inqueue[vex] = 1;
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
	while (scanf("%d %d", &V, &E) != EOF)
	{
		init();
		for (int i = 1; i < V; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[a].push_back(node(a, len));
		}
		int S, T;
		scanf("%d %d", &S, &T);
		int ans = Dijkstra(S, T);
		if (ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}