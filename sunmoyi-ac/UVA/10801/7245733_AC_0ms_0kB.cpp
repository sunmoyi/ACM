#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 110
#define maxm 10
#define INF 0x3f3f3f3f
using namespace std;

int f[maxm][maxn];
struct node {
	int v, len;
	node(int v = 0, int len = 0): v(v), len(len){}
	bool friend operator < (const node&a, const node&b)
	{
		return a.len > b.len;
	}
};
vector<node>G[maxn];
int n, aim;
int v[maxm];
bool inqueue[maxn];
int mindist[maxn];

void init()
{
	memset(mindist, INF, sizeof(mindist));
	memset(inqueue, false, sizeof(inqueue));
	for (int i = 0; i < maxn; i++)
		G[i].clear();
}

int Dijkstra(int s, int t)
{
	priority_queue<node>Q;
	mindist[s] = 0;
	inqueue[0] = true;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		inqueue[vex] = true;
		Q.push(G[s][i]);
		mindist[vex] = min(mindist[vex], G[s][i].len);
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
			if (len + mindist[now.v] + 60 < mindist[vex])
			{
				mindist[vex] = len + mindist[now.v] + 60;
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
	char ch, top;
	while (scanf("%d %d", &n, &aim) != EOF)
	{
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		for (int i = 1; i <= n; i++)
		{
			top = 0;
			while (scanf("%d%c", &f[i][top++], &ch))
			{
				for (int k = 0; k < top - 1; k++)
				{
					G[f[i][k]].push_back(node(f[i][top - 1], (f[i][top - 1] - f[i][k]) * v[i]));
					G[f[i][top - 1]].push_back(node(f[i][k], (f[i][top - 1] - f[i][k]) * v[i]));
				}
				if (ch == '\n')
					break;
			}
		}
		int ans = Dijkstra(0, aim);
		if (ans == INF)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}