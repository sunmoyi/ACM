#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define Min(x, y)(x < y? x: y)
using namespace std;
const int INF = 0xfffffff;
const int maxn = 210;
struct node{
	int v;
	int len;
	node(int v = 0, int len = 0) :v(v), len(len){}
	friend bool operator <(const node &a, const node &b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int minDist[maxn];
int cnt[maxn];
int n, m;
vector<node>G[maxn];

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		inqueue[i] = false;
		G[i].clear();
		minDist[i] = INF;
		cnt[i] = 0;
	}
}

int Djikstra(int S, int T)
{
	minDist[S] = 0;
	cnt[S]++;
	priority_queue<node>Q;
	for (int i = 0; i < G[S].size(); i++)
	{
		int vex = G[S][i].v;
		Q.push(G[S][i]);
		inqueue[vex] = 1;
		cnt[vex]++;
		minDist[vex] = min(minDist[vex], G[S][i].len);
	}
	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		inqueue[now.v] = 0;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			int len = G[now.v][i].len;
			if (minDist[vex] > len + minDist[now.v])
			{
				minDist[vex] = len + minDist[now.v];
				if (!inqueue[vex])
				{
					cnt[vex]++;
					if (cnt[vex] == n)
					{
						return INF;
					}
					inqueue[vex] = 1;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
	return minDist[T];
}

int main(void)
{
	while (cin >> n >> m)
	{
		init();
		int a, b, len;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		int S, T;
		scanf("%d %d", &S, &T);
		int ans = Djikstra(S, T);
		if (ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
