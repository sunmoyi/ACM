#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define maxx 1111000
using namespace std;

struct node {
	int to, next;
};
node edge[maxx];
int head[maxn], tot;
int linker[maxn];
bool used[maxn];
int uN;
int k1[maxn], k2[maxn];

inline void init(void)
{
	tot = 0;
	memset(head, -1, sizeof(head));
}

inline void addedge(int u, int v)
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

inline int hungary(void)
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
	int a;
	while (scanf_s("%d", &uN) != EOF)
	{
		init();
		for (int i = 1; i <= uN; i++)
		{
			for (int j = 1; j <= uN; j++)
			{
				scanf_s("%d", &a);
				if (a)
					addedge(i, j);
			}
		}

		int sum = hungary();
		//printf("%d\n", sum);
		if (sum < uN)
		{
			printf("-1\n");
		}
		else
		{
			int total = 0, j;
			for (int i = 1; i <= uN; i++)
			{
				for (j = 1; j <= uN && linker[j] != i; j++)
					;
				if (i != j)
				{
					k1[total] = i;
					k2[total] = j;
					total++;
					int temp = linker[i];
					linker[i] = linker[j];
					linker[j] = temp;
				}
			}
			printf("%d\n", total);
			for (int i = 0; i < total; i++)
				printf("C %d %d\n", k1[i], k2[i]);
		}
	}
	return 0;
}