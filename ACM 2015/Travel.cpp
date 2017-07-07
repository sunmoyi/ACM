#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20010

using namespace std;

int father[maxn], num[maxn];
int p[maxn];
int t, n, m, q;

struct query {
	int id, x;
	bool friend operator < (query A, query B)
	{
		return A.x < B.x;
	}
}que[maxn];

struct node {
	int u, v, w;
	node(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
	bool friend operator < (const node A, const node B)
	{
		return A.w < B.w;
	}
}edge[maxn * 4];

void init()
{
	for (int i = 1; i < maxn; i++)
	{
		num[i] = 1;
		father[i] = i;
	}
}

int find(int x)
{
	int far = x;
	while (far != father[far])
		far = father[far];

	int i = x;
	while (father[i] != far)
	{
		int temp = father[i];
		father[i] = far;
		i = temp;
	}

	return far;
}

void unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (y < x)
	{
		int temp = y;
		y = x;
		x = temp;
	}
	father[y] = x;
	num[x] += num[y];
}

int main (void)
{
	scanf("%d", &t);
	while (t--)
	{
		int ans = 0;
		scanf("%d %d %d", &n, &m, &q);
		init();
		for (int i = 1; i <= m; i++)
			scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		sort(edge, edge + m);

		int j = 0;
		for (int i = 0; i < q; i++)
		{
			que[i].id = i;
			scanf("%d", &que[i].x);
		}
		sort(que, que + q);

		for (int i = 0; i < q; i++)
		{
			while (j < m && edge[j].w <= que[i].x)
			{
				int u = find(edge[j].u);
				int v = find(edge[j].v);
				j++;
				if (u == v)
					continue;
				ans += (num[u] + num[v])*(num[u] + num[v] - 1) - num[u] * (num[u] - 1) - num[v] * (num[v] - 1);
				unoin(u, v);
			}
			p[que[i].id] = ans;
		}
		for (int i = 0; i < q; i++)
			printf("%d\n", p[i]);
	}
	return 0;
}

// abcdabcda
// 000012345