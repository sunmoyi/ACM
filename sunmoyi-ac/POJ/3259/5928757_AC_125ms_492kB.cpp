#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define inf 0xfffffff
#define maxn 10002

int V, E;

struct node
{
	int v;
	int len;
	node(int v = 0, int val = 0) :v(v), len(val) {}
};

vector<node> G[maxn + 2];
int mindist[maxn], cnt[maxn];
bool inqueue[maxn];

void init(void)
{
	for (int i = 1; i < maxn; i++)
	{
		mindist[i] = inf;
		cnt[i] = 0;
		inqueue[i] = 0;
		G[i].clear();
	}
}

int spfa(int s)
{
	stack<int>p;
	p.push(s);
	mindist[s] = 0;
	inqueue[s] = true;
	cnt[s]++;

	while (!p.empty())
	{
		int u = p.top();
		p.pop(); 
		inqueue[u] = false;
		int len = G[u].size();

		for (int j = 0; j < len; j++)
		{
			int v = G[u][j].v;
			int c = G[u][j].len;
			if (mindist[v] - c > mindist[u])
			{
				mindist[v] = c + mindist[u];
				if (!inqueue[v])
				{
					inqueue[v] = true; 
					if (++cnt[v] >= V) 
						return 1;
					p.push(v);
				}
			}
		}
	}
	return 0;
}
int main()
{
	int ans, a, b, c, len;
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			init();
			scanf("%d%d%d", &V, &E, &c);

			for(int i = 1; i <= E; i++)
			{
				scanf("%d%d%d", &a, &b, &len);
				G[a].push_back(node(b, len));
				G[b].push_back(node(a, len));
			}
			for(int i = 1; i <= c; i++)
			{
				scanf("%d%d%d", &a, &b, &len);
				G[a].push_back(node(b, -len));
			}
			if (spfa(1)) 
				puts("YES");
			else   
				puts("NO");
		}
	}
	return 0;
}