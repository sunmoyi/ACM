#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define Min(x, y) (x > y? x: y)
using namespace std;
const int INF = 0xfffffff;
const int maxn = 1010;

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
int cnt[maxn];
int n, m, kk;
int s, t;
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
	mindist[s] = 0;
	cnt[s]++;
	priority_queue<node>Q;
	for (int i = 0; i < G[s].size(); i++)
	{
		int vex = G[s][i].v;
		inqueue[vex] = true;
		cnt[vex]++;
		mindist[vex] = min(mindist[vex], G[s][i].len);
		Q.push(G[s][i]);
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
			if(mindist[vex] > len + mindist[now.v])
			{
				mindist[vex] = len + mindist[now.v];
				if (!inqueue[vex])
				{
					cnt[vex]++;
					if (cnt[vex] == n)
					{
						return;
					}
					inqueue[vex] = true;
					Q.push(G[now.v][i]);
				}
			}
		}
	}
	return;
}

int main(void)
{
	int a, b, len;
	while (scanf("%d %d %d", &n, &m, &t) != EOF)
	{
		init();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[b].push_back(node(a, len));
		}
		Dijkstra(t);
		scanf("%d", &kk);
		int minn = INF;
		for (int i = 1; i <= kk; i++)
		{
			scanf("%d", &s);
			minn = min(minn, mindist[s]);
		}
		if (minn == INF)
			printf("-1\n");
		else
			printf("%d\n", minn);
	}
	return 0;
}