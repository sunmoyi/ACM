#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int b;
	int len;
	node(int b, int len) :b(b), len(len) {}
	bool friend operator < (const node&a, const node&b)
	{
		return a.len < b.len;
	}
};

vector<node>G[10005];
int E, V;
bool vis[10005];
int S, T;
int mindist[10005];

void spfa(void)
{
	for (int i = 0; i <= V; i++)
	{
		mindist[i] = 0xffffff;
	}
	queue<int>Q;
	mindist[S] = 0;
	vis[S] = true;
	Q.push(S);
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		vis[now] = false;
		for (int i = 0; i < G[now].size(); i++)
		{
			int next = G[now][i].b;
			int len = G[now][i].len;
			if (mindist[next] > mindist[now] + len)
			{
				mindist[next] = mindist[now] + len;
				if (!vis[next])
				{
					vis[next] = true;
					Q.push(next);
				}
			}
		}
	}
}

int main(void)
{
	int a, b, c;
	while (scanf("%d %d", &E, &V) != EOF)
	{
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(node(b, c));
			G[b].push_back(node(a, c));
		}
		S = 1;
		T = V;
		spfa();
		printf("%d\n", mindist[V]);
	}
	return 0;
}