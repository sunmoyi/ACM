#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxx 105
#define maxn 1000005
#define INF 0xfffffff
using namespace std;

struct node {
	int x;
	int y;
};
node a[maxx];
bool used[maxn];
int linker[maxn];
int ans, sum;
int ss[105];

inline void init(void)
{
	memset(ss, -1, sizeof(ss));
}

bool dfs(int u)
{
	for (int i = a[u].x; i <= a[u].y; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			if (linker[i] == -1 || dfs(linker[i]))
			{
				linker[i] = u;
				//ss[u] = 1;
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
	for (int i = sum; i >= 1; i--)
	{
		memset(used, 0, sizeof(used));
		if (dfs(i))
		{
			ss[i] = 1;
			res++;
		}
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
			scanf_s("%d", &sum);
			for (int i = 1; i <= sum; i++)
			{
				scanf_s("%d %d", &a[i].x, &a[i].y);
			}

			int maxxx = hungary();
			printf("%d\n", maxxx);
			for (int i = 1; i <= sum - 1; i++)
			{
				if (ss[i] == 1)
					printf("%d ", i);
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}