#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 0xfffffff
#define maxn 1005
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
vector<node>G[maxn];
int V, E;
int mindist[maxn];

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		mindist[i] = INF;
		G[i].clear();
	}
}

int Bellman_ford(int s, int t)
{
	mindist[s] = 0;
	int cnt = 0;
	while (true)
	{
		bool change = false;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < G[V].size(); i++)
			{
				if (mindist[V] + G[V][i].len < mindist[G[V][i].v] && mindist[V] != INF)
				{
					mindist[G[V][i].v] = mindist[V] + G[V][i].len;
					change = true;
				}
			}
		}
		if (!change)
			break;
		if (++cnt == V)
			return -1;
	}
	return mindist[t];
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
		}
		int S, T;
		scanf("%d %d", &S, &T);
		int dis = Bellman_ford(S, T);
		if (dis = -1)
			printf("wrong!\n");
		else
			printf("%d\n", dis);
	}
	return 0;
}