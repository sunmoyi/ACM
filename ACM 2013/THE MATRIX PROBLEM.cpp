#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define size 100000

using namespace std;

int n, m;
double u, l;
struct edge {
	int to, next; double val;
} e[400 * 400 * 10];
int cnt, v[1000];
bool vis[1000];
double mindist[1000];

void insert(int from, int to, double val)
{
	e[cnt].val = val;
	e[cnt].to = to;
	e[cnt].next = v[from];
	v[from] = cnt++;
}

bool spfa(int lar)
{
	for (int i = 0; i < lar; i++)
		vis[i] = 0, mindist[i] = 10000000;
	mindist[0] = 0;
	queue<int> que;
	vis[0] = 1;
	que.push(0);
	int sum = 0;
	while (!que.empty())
	{
		int u = que.front();
		vis[u] = 0;
		que.pop();
		for (int i = v[u]; i != -1; i = e[i].next)
		{
			double w = e[i].val;
			int v = e[i].to;
			if (mindist[u] + w< mindist[v])
			{
				mindist[v] = mindist[u] + w;
				if (!vis[v])
				{
					vis[v] = 1;
					que.push(v);
					sum++;
					if (sum > 2 * (lar + 2 * m))
						return 0;
				}
			}
		}
	}
	return true;
}

int main()
{
	while (scanf_s("%d%d%lf%lf", &n, &m, &l, &u) != EOF)
	{
		cnt = 0;
		memset(v, -1, sizeof(int) * (n + m + 2));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int tmp;
				scanf_s("%d", &tmp);
				insert(i, n + j, -log(l / tmp));
				insert(n + j, i, log(u / tmp));
			}
		}

		if (spfa(n + m))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}