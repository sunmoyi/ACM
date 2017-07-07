#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxx 1050
#define maxy 3050

using namespace std;

vector<int>G[maxx];
struct node {
	int to;
	int next;
}edge[maxx * maxy];
int head[maxx], tot;
int linker[maxx];
bool used[maxx];
int uN, uV;
int ans;

void init(void)
{
	for (int i = 0; i < maxx; i++)
		G[i].clear();
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
	memset(linker, -1, sizeof(linker));//!!!!!!!!!!!!!
	for (int u = 1; u <= uN; u++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(u))
			res++;
	}
	return res;
}

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			init();
			scanf_s("%d %d", &uN, &uV);
			for (int i = 1; i <= uN; i++)
			{
				int a, b;
				scanf_s("%d", &a);
				for (int j = 1; j <= a; j++)
				{
					scanf_s("%d", &b);
					addedge(i, b + uN);
				}
			}
			int kk = hungary();
			//printf("%d", kk);
			if (hungary() == uN)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}