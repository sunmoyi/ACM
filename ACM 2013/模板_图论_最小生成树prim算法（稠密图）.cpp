#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
#define INF 0xfffffff
using namespace std;

struct node{
	int v;
	int len;
	node(int v = 0, int len = 0) : v(v), len(len){}
	friend bool operator <(const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
bool intree[maxn];
int mindist[maxn];
int V, E;
vector<node>G[maxn];

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		intree[i] = false;
		mindist[i] = INF;
		G[i].clear();
	}
}

int prim()
{
	int sum = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[0].size(); i++)
	{
		mindist[G[0][i].v] = G[0][i].len;
		Q.push(G[0][i]);
	}
	intree[0] = true;

	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		if (intree[now.v])
			continue;
		intree[now.v] = true;
		sum += now.len;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			int len = G[now.v][i].len;
			if (len < mindist[vex])
			{
				mindist[vex] = len;
				Q.push(G[now.v][i]);
			}
		}
	}
	return sum;
}

int main(void)
{
	int a, b, len;
	while (scanf("%d %d", &V, &E) != EOF)
	{
		init();
		for (int i = 1; i <= V; i++)
		{
			scanf("%d %d %d", &a, &b, &len);
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
		int minn = prim();
		printf("%d\n", minn);
	}
	return 0;
}