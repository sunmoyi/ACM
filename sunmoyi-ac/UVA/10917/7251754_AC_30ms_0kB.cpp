/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 1010
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int v, len;
	node(int v = 0, int len = 0) :v(v), len(len){}
	bool friend operator < (const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
vector<node>G[maxn];
int inqueue[maxn];
int mindist[maxn];
int dp[maxn];
int n, m;

void init(void)
{
	memset(inqueue, false, sizeof(inqueue));
	memset(mindist, INF, sizeof(mindist));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < maxn; i++)
		G[i].clear();
}

int Dijkstra(int s)
{
	inqueue[s] = true;
	mindist[s] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		mindist[vex] = min(mindist[vex], G[s][i].len);
		inqueue[vex] = true;
		Q.push(G[s][i].v);
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
				mindist[vex] = len + mindist[now.v];
				if (!inqueue[vex])
				{
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
}

int DP(int s)
{
	if (s == 2)
		return 1;
	if (dp[s] != -1)
		return dp[s];
	int ans = 0;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		if (mindist[vex] < mindist[s])
			ans += DP(vex);
	}
	return dp[s] = ans;
}

int main(void)
{
	int a, b, len;
	while (scanf("%d", &n) != EOF && n)
	{
		init();
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		Dijkstra(1);
		printf("%d\n", DP(1));
	}
	return 0;
}*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int n, m, s, t;

int vis[N], d[N];
int map[N][N];
int dp[N];
void init() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n; i++) vis[i] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = INF;
		}
	}
}

void input() {
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (c > map[a][b]) continue;
		map[a][b] = map[b][a] = c;
	}
}
void SPFA() {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; i++) d[i] = INF;
	d[t] = 0;
	vis[t] = 1;
	queue<int> Q;
	Q.push(t);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		vis[u] = 0;
		for (int i = 1; i <= n; i++) {
			if (map[u][i] == INF || u == i) continue;
			if (d[i] > d[u] + map[u][i]) {
				d[i] = d[u] + map[u][i];
				if (!vis[i]) {
					vis[i] = 1;
					Q.push(i);
				}
			}
		}
	}
}

int DFS(int pos) {
	if (pos == 2) return 1;
	if (dp[pos] > 0) {
		return dp[pos];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (d[pos] > d[i] && map[pos][i] != INF) {
			ans += DFS(i);
		}
	}
	return dp[pos] = ans;
}

int main() {
	s = 1, t = 2;
	while (scanf("%d", &n) != EOF, n) {
		init();
		scanf("%d", &m);
		input();
		SPFA();
		printf("%d\n", DFS(1));
	}
	return 0;
}