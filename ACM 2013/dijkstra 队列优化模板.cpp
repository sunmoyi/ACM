#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#define Min(x,y) (x < y ? x: y)
const int INF = 0xfffffff;
const int maxn = 210;
using namespace std;
struct node{
	int v, len;
	node(int v = 0, int len = 0) :v(v), len(len){}
	friend bool operator <(const node &a, const node&b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int minDist[maxn];
int cnt[maxn]; //判断负环；
int n, m;
vector<node>G[maxn];

void init()
{
	for (int i = 0; i < maxn; i++)
	{
		minDist[i] = INF;
		G[i].clear();
		inqueue[i] = false;
		cnt[i] = 0;
	}
}

int Dijktra(int S, int T)
{
	minDist[S] = 0;
	cnt[S]++;
	priority_queue<node>Q;
	for (int i = 0; i < G[S].size(); i++)
	{
		int vex = G[S][i].v;
		Q.push(G[S][i]);
		cnt[vex]++;
		minDist[vex] = min(G[S][i].len, minDist[vex]);
		inqueue[vex] = 1;
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
			if (len + minDist[now.v] < minDist[vex])
			{
				minDist[vex] = len + minDist[now.v]; //先更新最短路径
				if (!inqueue[vex])
				{ //如果没在队列，再加入队列
					cnt[vex]++;
					if (cnt[vex] == n)
						return INF;
					inqueue[vex] = 1;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
	return minDist[T];
}
int main()
{
	while (cin >> n >> m)
	{
		init();
		int a, b, len;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		int S, T;
		scanf("%d%d", &S, &T);
		int ans = Dijktra(S, T);
		if (ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
