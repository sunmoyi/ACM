#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v, len;
	node(int v = 0, int len = 0) : v(v), len(len){}
	bool friend operator < (const node&a, const node&b)
	{
		return a.len < b.len;
	}
};

vector<node>G[maxn];
vector<node>GT[maxn];
int V, E, start;
bool inqueue[maxn];
int minn[maxn];
int minnT[maxn];

void init(void)
{
	for (int i = 1; i < maxn; i++)
	{
		minn[i] = INF;
		G[i].clear();
		GT[i].clear();
		minnT[i] = INF;
		inqueue[i] = false;
	}
}

void Dijkstra(vector<node>G[], int ans[])
{
	memset(inqueue, false, sizeof(inqueue));
	priority_queue<node>Q;
	ans[start] = 0;
	for (int i = 0; i < G[start].size(); i++)
	{
		int vex = G[start][i].v;
		Q.push(G[start][i]);
		inqueue[vex] = true;
		ans[vex] = min(ans[vex], G[start][i].len);
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
			if (len + ans[now.v] < ans[vex])
			{
				ans[vex] = len + ans[now.v];
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
	int a, b, len;
	while (scanf("%d %d %d", &V, &E, &start) != EOF)
	{
		init();
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			GT[b].push_back(node(a, len));
		}
		Dijkstra(G, minn);
		Dijkstra(GT, minnT);

		int maxx = 0;
		for (int i = 1; i <= V; i++)
			maxx = max(maxx, minn[i] + minnT[i]);

		printf("%d\n", maxx);
	}
	return 0;
}