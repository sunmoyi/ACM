#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define inf 99999999
#define V 520
#define NE 6000
int n, m, w;

struct node
{
	int v;
	int val;
	node(int v = 0, int val = 0) :v(v), val(val) {}
}E;

vector<node> Node[V + 2];
int d[V], cnt[V], inqueue[V];

void init(void)
{
	for (int i = 1; i < V; i++)
	{
		d[i] = inf;
		cnt[i] = 0;
		inqueue[i] = 0;
		Node[i].clear();
	}
}
int spfa(int k)
{
	d[k] = 0; 
	inqueue[k] = 1; 
	cnt[k] = 1;

	stack<int> p; p.push(k);
	while (!p.empty())
	{
		int u = p.top();
		p.pop(); inqueue[u] = 0;
		int len = Node[u].size();

		for (int j = 0; j < len; j++)
		{
			int v = Node[u][j].v;
			int c = Node[u][j].val;
			if (d[v] - c > d[u])
			{
				d[v] = c + d[u];
				if (!inqueue[v])
				{
					inqueue[v] = 1; 
					cnt[v] ++;
					if (cnt[v] >= n) 
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
	int cs;
	scanf("%d", &cs);
	while (cs--)
	{
		init();
		scanf("%d%d%d", &n, &m, &w);


		while (m--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			E.v = b; E.val = c;
			Node[a].push_back(E);

			E.v = a; E.val = c;
			Node[b].push_back(E);
		}
		while (w--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			E.v = b; E.val = -c;
			Node[a].push_back(E);
		}
		if (!spfa(1)) puts("NO");
		else   puts("YES");
	}
	return 0;
}