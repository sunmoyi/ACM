#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxx 110000
#define maxn 50500

using namespace std;

struct node {
	int to, next;
}edge[maxx];
int head[maxn],tot;
int linker[maxn];
bool  used[maxn];
int uN;

void init(void)
{
	tot = 0;
	memset(head, -1, sizeof(head));
}

void addedge(int u, int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

bool dfs(int u)
{
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (!used[v])
		{
			used[v] = true;
			if (linker[v] == -1 || dfs(linker[v]))
			{
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary(void)
{
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for (int i = 1; i <= uN; i++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(i))
			res++;
	}
	return res;
}

int main(void)
{
	int sum, a, b, n, m;
	while (scanf_s("%d", &sum) != EOF && sum)
	{
		init();
		scanf_s("%d %d", &a, &b);
		uN = a;
		for (int i = 1; i <= sum; i++)
		{
			scanf_s("%d %d", &n, &m);
			addedge(n, m + a);
		}
		int sum = hungary();
		printf("%d\n", sum);
	}
	return 0;
}