#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 50010
#define INF 0xfffffff

using namespace std;

struct node{
	int v, len;
	node(int v = 0, int len = 0) :v(v), len(len) {}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int mindist[maxn];
vector<node>G[maxn];
int ans;

void init()
{
	for (int i = 0; i < maxn; i++)
	{
		mindist[i] = -INF;
		G[i].clear();
		inqueue[i] = false;
	}
}

int Dijkstra(int S, int T)
{
	mindist[S] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[S].size(); i++)
	{
		int vex = G[S][i].v;
		inqueue[vex] = true;
		Q.push(G[S][i]);
		mindist[vex] = max(G[S][i].len, mindist[vex]);
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
			if (len + mindist[now.v] <= mindist[vex])
				continue;
			else
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
	return mindist[T];
}

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		int a, b, c, minn = INF, maxx = -INF;
		init();
		for (int i = 1; i <= ans; i++)
		{
			scanf_s("%d %d %d", &a, &b, &c);
			G[a].push_back(node(b + 1, c));
			minn = minn < a ? minn : a;
			maxx = maxx > b ? maxx : b;
		}
		for (int i = minn; i <= maxx + 1; i++)
		{
			G[i].push_back(node(i - 1, -1));
			G[i - 1].push_back(node(i, 0));
		}
		printf("%d\n", Dijkstra(minn, maxx + 1));
	}
	return 0;
}