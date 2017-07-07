#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 230

using namespace std;

int n;
bool G[maxn][maxn];
int f[maxn];

struct node {
	int x, y, h;
}A[maxn];

bool check(int i, int j)
{
	return ((A[i].x < A[j].x && A[i].y < A[j].y) || (A[i].y < A[j].x && A[i].x < A[j].y));
}

int dfs(int u)
{
	if (f[u] != -1)
		return f[u];

	f[u] = A[u].h;
	for (int i = 0; i < n; i++)
	{
		if (G[u][i])
			f[u] = max(f[u], dfs(i) + A[u].h);
	}
	return f[u];
}

int main(void)
{
	int icase = 1;
	while (scanf("%d", &n) != EOF && n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &A[i].x, &A[i].y, &A[i].h);
			A[n + i].x = A[i].x;   A[n + i].y = A[i].h;   A[n + i].h = A[i].y;
			A[2 * n + i].x = A[i].y; A[2 * n + i].y = A[i].h; A[2 * n + i].h = A[i].x;
		}

		n *= 3;

		memset(G, 0, sizeof(G));
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				G[i][j] = check(i, j);
				G[j][i] = check(j, i);
			}
		}
		int ans = 0;
		memset(f, -1, sizeof(f));
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, dfs(i));
		}
		printf("Case %d: maximum height = %d\n", icase++, ans);
	}
	return 0;
}