#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v;
	int len;
	node(int v = 0, int len = 0) : v(v), len(len) {}
	friend bool operator < (const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
vector<node>G[maxn];
vector<node>F[maxn];
int mindist[maxn];
int V, E;
bool inqueue[maxn];

void init(void)
{
	for (int i = 0; i <= V + 1; i++)
	{
		G[i].clear();
		F[i].clear();
		inqueue[i] = false;
		mindist[i] = INF;
	}
}

void init2(void)
{
	for (int i = 0; i <= V + 1; i++)
	{
		inqueue[i] = false;
		mindist[i] = INF;
	}
}

void Dijkstra(vector<node> *S, int s)
{
	mindist[s] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < S[s].size(); i++)
	{
		int vex = S[s][i].v;
		inqueue[vex] = true;
		Q.push(S[s][i]);
		if (mindist[vex] > S[s][i].len)
			mindist[vex] = S[s][i].len;
	}
	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		inqueue[now.v] = false;
		for (int i = 0; i < S[now.v].size(); i++)
		{
			int vex = S[now.v][i].v;
			int len = S[now.v][i].len;
			if (len + mindist[now.v] < mindist[vex])
			{
				mindist[vex] = mindist[now.v] + len;
				if (!inqueue[vex])
				{
					inqueue[vex] = true;
					Q.push(S[now.v][i]);
				}
			}
		}
	}
}

int main(void)
{
	int T, a, b, len;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			scanf("%d %d", &V, &E);
			init();
			for (int i = 1; i <= E; i++)
			{
				scanf("%d %d %d", &a, &b, &len);
				G[a].push_back(node(b, len));
				F[b].push_back(node(a, len));
			}
			long long ans = 0;
			Dijkstra(G, 1);
			for (int i = 2; i <= V; i++)
				ans += mindist[i];
			//printf("%lld\n", ans);
			init2();
			Dijkstra(F, 1);
			for (int i = 2; i <= V; i++)
				ans += mindist[i];
			printf("%lld\n", ans);
		}
	}
	return 0;
}