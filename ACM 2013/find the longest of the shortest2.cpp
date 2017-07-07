#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define Min(x, y)(x > y? x: y)
using namespace std;
const int INF = 0xfffffff;
const int maxn = 1005;
struct node{
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
int n, m;
int f[maxn];
int cnt[maxn];
vector<node>G[maxn];
priority_queue<node>Q;

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		inqueue[i] = false;
		mindist[i] = INF;
		G[i].clear();
		f[i] = -1;
		cnt[i] = 0;
	}
}

void init2(void)
{
	for (int i = 0; i < maxn; i++)
	{
		inqueue[i] = false;
		mindist[i] = INF;
		cnt[i] = 0;
	}
}

void Dijkstra(int s)
{
	mindist[1] = 0;
	cnt[1]++;
	for (int i = 0; i < G[1].size(); i++)
	{
		int vex = G[1][i].v;
		inqueue[vex] = true;
		Q.push(G[1][i]);
		mindist[vex] = min(G[1][i].len, mindist[vex]);
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
			if (mindist[vex] > len + mindist[now.v])
			{
				mindist[vex] = len + mindist[now.v];
				if (s)
					f[vex] = now.v;
				if (!inqueue[vex])
				{
					cnt[vex]++;
					if (cnt[vex] == n)
						return;
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
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		Dijkstra(1);
		int j = n;
		int maxx = -1;
		int x, y, v;
		while (f[j] > 0)
		{
			for (int i = 0; i < G[j].size(); i++)
			{
				if (G[j][i].v == f[j])
				{
					v = G[j][i].len;
					G[j][i].len = INF;
					x = i;
					break;
				}
			}
			for (int i = 0; i < G[f[j]].size(); i++)
			{
				if(G[f[j]][i].v == j)
				{
					G[f[j]][i].len = INF;
					y = i;
					break;
				}
			}
			init2();
			Dijkstra(0);
			G[j][x].len = v;
			G[f[j]][y].len = v;
			j = f[j];
			if (mindist[n] > maxx && mindist[n] < INF)
				maxx = mindist[n];
		}
		printf("%d\n", maxx);
	}
	return 0;
}