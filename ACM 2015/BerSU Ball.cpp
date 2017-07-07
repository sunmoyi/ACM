#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define maxn 110

using namespace std;

int n, m;
int male[maxn];
int famale[maxn];
vector<int>G[maxn];
bool vis[maxn];
int linker[maxn];

bool find(int u)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!vis[v])
		{
			vis[v] = true;
			if (linker[v] == -1 || find(linker[v]))
			{
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungry()
{
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (find(i))
			res++;
	}
	return res;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &male[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &famale[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (abs(male[i] - famale[j]) <= 1)
				G[i].push_back(j);
	printf("%d\n", hungry());
	return 0;
}