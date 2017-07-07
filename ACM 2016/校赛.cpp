#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 110
#define INF 0x3f3f3f3f
using namespace std;

struct node {
	int v, len;
	node(int v = 0, int len = 0) :v(v), len(len){}
	bool friend operator < (const node &a, const node&b)
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

int Dijkstra(int S, int T)
{
	mindist[S] = 0;
	cnt[S]++;
	priority_queue<node>Q;
	for (int i = 0; i < G[S].size(); i++)
	{
		int vex = G[S][i].v;
		Q.push(G[S][i]);
		inqueue[vex] = true;
		mindist[vex] = min(G[S][i].len, mindist[vex]);
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
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
					if (++cnt[vex] == n)
						return INF;
				}
			}
		}
	}
	return mindist[T];
}

int main (void)
{
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		init();
		int a, b, len;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		printf("%d\n", Dijkstra(1, n));
	}
	return 0;
}