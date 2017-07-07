//UVA 11734
//ÕÒLrj Ô´Âë
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn  510
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v, len;
	node(int v = 0, int len = 0) :v(v), len(len){}
	bool friend operator < (const node&a, const node&b)
	{
		return a.len > b.len;
	}
};
vector<node>G[maxn];
int inqueue[maxn];
int mindists[maxn], mindiste[maxn];
vector<int>paths[maxn], pathe[maxn];
int pS[maxn], pE[maxn];
int V, S, E, M, N, K;

void init(void)
{
	for (int i = 1; i < maxn; i++)
	{
		G[i].clear();
		paths[i].clear();
		pathe[i].clear();
		pS[i] = i;
		pE[i] = i;
	}
	memset(mindiste, INF, sizeof(mindiste));
	memset(mindists, INF, sizeof(mindists));
}

void Dijkstra(int s, int mindist[], int p[])
{
	inqueue[s] = true;
	mindist[s] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		inqueue[vex] = true;
		p[vex] = s;
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
			if (len + mindist[now.v] < mindist[vex])
			{
				mindist[vex] = mindist[now.v] + len;
				p[vex] = now.v;
				if (!inqueue[vex])
				{
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
}

void getpath(vector<int>path[], int s, int p[])
{
	for (int i = 1; i <= V; i++)
	{
		int t = i;
		while (t != s)
		{
			path[i].push_back(p[t]);
			t = p[t];
		}
		reverse(path[i].begin(), path[i].end());
	}
}

int main(void)
{
	int a, b, len, Case = 0;
	while (scanf("%d %d %d %d", &V, &S, &E, &M) != EOF)
	{
		init();
		for (int i = 1; i <= M; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		memset(inqueue, false, sizeof(inqueue));
		Dijkstra(S, mindists, pS);
		memset(inqueue, false, sizeof(inqueue));
		Dijkstra(E, mindiste, pE);
		getpath(paths, S, pS);
		getpath(pathe, E, pE);

		vector<int>path;
		scanf("%d", &K);
		int ans = INF, s = -1, e = -1;
		for (int i = 1; i <= K; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			if (mindists[a] + mindiste[b] + len < ans)
			{
				ans = mindists[a] + mindiste[b] + len;
				s = a, e = b;
				path = paths[s];
				path.push_back(s);
				for (int j = pathe[e].size() - 1; j >= 0; j--)
					path.push_back(pathe[e][j]);
			}
			if (mindists[b] + mindiste[a] + len < ans)
			{
				ans = mindists[b] + mindiste[a] + len;
				s = b, e = a;
				path = paths[s];
				for (int j = pathe[e].size() - 1; j >= 0; j--)
					path.push_back(pathe[e][j]);
			}
		}
		if (Case++)
			printf("\n");
		for (int i = 0; i < path.size(); i++)
			printf("%d ", path[i]);
		printf("%d\n", E);
		if (s == -1)
			printf("Ticket Not Used\n");
		else
			printf("%d\n", s);
		printf("%d\n", ans);
	}
	return 0;
}