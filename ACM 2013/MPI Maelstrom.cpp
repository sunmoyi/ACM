#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 110
#define INF 0xfffffff

using namespace std;

struct node {
	int len;
	int v;
	node(int v = 0, int len = 0) : v(v), len(len) {}
	bool friend operator < (const node&a, const node&b)
	{
		return a.len < b.len;
	}
};
bool inqueue[maxn];
int mindist[maxn];
vector<node>G[maxn];
int V;
char str[10];

int number(void)
{
	if (str[0] == 'x')
		return 0;
	else
		return atoi(str);
}

void init(void)
{
	for (int i = 0; i < maxn; i++)
	{
		inqueue[i] = false;
		mindist[i] = INF;
		G[i].clear();
	}
}
void Dijkstra(void)
{
	mindist[1] = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[1].size(); i++)
	{
		int vex = G[1][i].v;
		inqueue[vex] = true;
		mindist[vex] = min(mindist[vex], G[1][i].len);
		Q.push(G[1][i]);
	}
	
	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		inqueue[now.v] = false;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int len = G[now.v][i].len;
			int vex = G[now.v][i].v;
			if (len + mindist[now.v] < mindist[vex])
			{
				mindist[vex] = len + mindist[now.v];
				if (!inqueue[vex])
				{
					Q.push(G[now.v][i]);
					inqueue[vex] = true;
				}
			}
		}
	}
}

int main(void)
{
	while (scanf("%d", &V) != EOF)
	{
		init();
		for (int i = 2; i <= V; i++)
		{
			for (int j = 1; j < i; j++)
			{
				scanf("%s", str);
				int dis = number();
				if (dis != 0)
				{
					
					G[i].push_back(node(j, dis));
					G[j].push_back(node(i, dis));
				}
			}
		}
		Dijkstra();
		int maxx = 0;
		for (int i = 2; i <= V; i++)
		{
			maxx = max(maxx, mindist[i]);
		}
		printf("%d\n", maxx);
	}
	return 0;
}