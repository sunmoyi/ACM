#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define maxm 220
#define INF 0xfffffff

using namespace std;

struct node {
	int len;
	int from;
	int to;
	node(int from = 0, int to = 0, int len = 0) :from(from), to(to), len(len){}
	friend bool operator < (const node &a, const node&b)
	{
		return a.len < b.len;
	}
}edge[maxm];
int n, m;
int father[maxn];
int rankk[maxn];
int ms_edge[maxn];

void init(int x)
{
	for (int i = 0; i <= x; i++)
	{
		father[i] = i;
		rankk[i] = 0;
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

bool unoin(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;

	if (rankk[x] < rankk[y])
		father[x] = y;
	else
	{
		father[y] = x;
		if (rankk[x] == rankk[y])
		{
			rankk[x]++;
		}
	}
	return true;
}

int kruskal(void)
{
	int k = 0;
	memset(ms_edge, 0, sizeof(ms_edge));
	int ans = 0;
	for (int i = 1; i <= m && k < n - 1; i++)
	{
		if (unoin(edge[i].from, edge[i].to))
		{
			ans += edge[i].len;
			k++;
			ms_edge[k] = i;
		}
	}
	if (k == n - 1)
		return ans;
	else
		return -1;
}

int smst(void)
{
	int Min = INF;
	for (int i = 1; i <= n - 1; i++)
	{
		int ans = 0, k = 0;
		init(n);
		for (int j = 1; j <= m && k < n - 1; j++)
		{
			if (j == ms_edge[i])
				continue;
			if (unoin(edge[j].from, edge[j].to))
			{
				k++;
				ans += edge[j].len; 
			}
		}
		if (k == n - 1)
			Min = min(Min, ans);
	}
	if (Min == INF)
		return -1;
	else
		return Min;
}

int main(void)
{
	int T;
	int u, v, w;
	scanf("%d", &T);
	for(int ss = 1; ss <= T; ss++)
	{
		scanf("%d %d", &n, &m);
		init(n);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			edge[i].from = u;
			edge[i].to = v;
			edge[i].len = w;
		}
		sort(edge + 1, edge + 1 + m);
		printf("Case #%d : ", ss);
		int ans = kruskal();
		if (ans == -1)
			printf("No way\n");
		else
		{
			int ans = smst();
			if (ans == -1)
				printf("No second way\n");
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}