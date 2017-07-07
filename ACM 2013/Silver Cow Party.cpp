#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 0xfffffff
using namespace std;

struct node {
	int v;
	int len;
	node(int v = 0, int len = 0) : v(v), len(len) {}
	bool friend operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};

vector<node>G[1005];
vector<node>GX[1005];
int V, E, start;
bool inqueue[1005];
int minn[1005];
int minnx[1005];

void init(void)
{
	for (int i = 1; i <= 1004; i++)
	{
		minn[i] = INF;
		G[i].clear();
		GX[i].clear();
		minnx[i] = INF;
		inqueue[i] = false;
	}
}

void Dijkstra(vector<node>G[], int ans[])
{
	memset(inqueue, 0, sizeof(inqueue));
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

int main(void)
{
	int a, b, len;
	while (scanf("%d %d %d", &V, &E, &start) != EOF)
	{
		init();
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			GX[b].push_back(node(a, len));
		}
		Dijkstra(G, minn);
		Dijkstra(GX, minnx);
		int ans;
		int maxx = 0;
		for (int i = 1; i <= V; i++)
		{
			ans = minn[i] + minnx[i];
			maxx = (maxx > ans ? maxx : ans);
		}
		printf("%d\n", maxx);
	}
	return 0;
}