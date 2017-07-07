#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define inf 99999999
#define maxn 520

int v1, E, w;

struct node
{
	int v;
	int val;
	node(int v = 0, int val = 0) :v(v), val(val) {}
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
	mindist[s] = 0;
	inqueue[s] = true; 
	cnt[s]++;

	stack<int> p; p.push(s);
	while (!p.empty())
	{
		int u = p.top();
		p.pop(); 
		inqueue[u] = false;
		int len = G[u].size();

		for (int j = 0; j < len; j++)
		{
			int v = G[u][j].v;
			int c = G[u][j].val;
			if (mindist[v] - c > mindist[u])
			{
				mindist[v] = c + mindist[u];
				if (!inqueue[v])
				{
					inqueue[v] = true; 
					if (++cnt[v] >= v1) 
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
	int cs, a, b, c;
	while (scanf("%d", &cs) != EOF)
	{
		while (cs--)
		{
			init();
			scanf("%d%d%d", &v1, &E, &w);

			while (E--)
			{
				scanf("%d%d%d", &a, &b, &c);
				G[a].push_back(node(b, c));
				G[b].push_back(node(a, c));
			}
			while (w--)
			{
				scanf("%d%d%d", &a, &b, &c);
				G[a].push_back(node(b, -c));
			}
			if (!spfa(1)) puts("NO");
			else   puts("YES");
		}
	}
	return 0;
}