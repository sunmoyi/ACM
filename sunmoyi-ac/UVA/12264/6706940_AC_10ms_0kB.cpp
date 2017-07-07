#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;
const int maxn = 410;
const int inf = 1e9;
struct Edge {
	int v, c, next;
	Edge() {}
	Edge(int v, int c, int next) : v(v), c(c), next(next) {}
}edge[1000006];

int head[maxn], E;
int n, m;
int S, T;

void init()
{
	E = 0;
	memset(head, -1, sizeof(head));
}
void add(int s, int t, int c)
{
	edge[E] = Edge(t, c, head[s]);
	head[s] = E++;
	edge[E] = Edge(s, 0, head[t]);
	head[t] = E++;
}

int gap[maxn], dis[maxn], pre[maxn], cur[maxn];
int sap(int s, int t, int n)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		cur[i] = head[i];
		gap[i] = dis[i] = 0;
	}
	gap[0] = n;
	int u = pre[s] = s, maxf = 0, v, aug = inf;
	while (dis[s] < n)
	{
	loop:for (i = cur[u]; ~i; i = edge[i].next)
	{
		v = edge[i].v;
		if (edge[i].c && dis[u] == dis[v] + 1)
		{
			pre[v] = u;
			cur[u] = i;
			aug = min(aug, edge[i].c);
			u = v;
			if (u == t)
			{
				while (u != s)
				{
					u = pre[u];
					edge[cur[u]].c -= aug;
					edge[cur[u] ^ 1].c += aug;
				}
				maxf += aug;
				aug = inf;
			}
			goto loop;
		}
	}
		 int d = n;
		 for (i = head[u]; ~i; i = edge[i].next)
		 {
			 v = edge[i].v;
			 if (edge[i].c && dis[v] < d)
			 {
				 d = dis[v];
				 cur[u] = i;
			 }
		 }
		 if (!(--gap[dis[u]])) break;
		 ++gap[dis[u] = d + 1];
		 u = pre[u];
	}
	return maxf;
}
int a[maxn];
char mp[maxn][maxn];
int sum, ans;

void build(int m)
{
	int i, j;
	sum = 0;
	init();
	for (i = 0; i < n; i++)
		if (a[i])
		{
			add(S, i, a[i]);
			add(i, i + n, a[i]);
		}
	for (i = 0; i < n; i++) 
		if (a[i])
	{
		bool g = 0;
		for (j = 0; j < n; j++) if (mp[i][j] == 'Y')
		{
			if (a[j])
				add(i, j + n, inf);
			else 
				g = 1;
		}
		if (!g) 
			add(i + n, T, 1), sum++;
		else 
			add(i + n, T, m), sum += m;
	}
}
int main()
{
	int i, j, cas;
	scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ca++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
			scanf("%s", mp[i]);
		S = 2 * n; T = S + 1;
		int l = 1, r = 10000;
		while (l <= r)
		{
			int mid = l + r >> 1;
			build(mid);
			int tp = sap(S, T, T + 1);
			if (tp < sum) r = mid - 1;
			else
			{
				ans = mid;
				l = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}