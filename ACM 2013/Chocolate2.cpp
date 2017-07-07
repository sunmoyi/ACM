#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 505
#define INF 0xfffffff

using namespace std;

int nx, ny;
int G[maxn][maxn];
int linker[maxn], lx[maxn], ly[maxn];
int slack[maxn];
bool visx[maxn], visy[maxn];
int ans;

bool dfs(int x)
{
	visx[x] = true;
	for (int y = 1; y <= ny; y++)
	{
		if (visy[y])
			continue;
		int temp = lx[x] + ly[y] - G[x][y];
		if (temp == 0)
		{
			visy[y] = true;
			if (linker[y] == -1 || dfs(linker[y]))
			{
				linker[y] = x;
				return x;
			}
		}
		else if (slack[y] > temp)
			slack[y] = temp;
	}
	return false;
}

int KM()
{
	memset(linker, -1, sizeof(linker));
	memset(ly, 0, sizeof(ly));
	for (int i = 1; i <= nx; i++)
	{
		lx[i] = -INF;
		for (int j = 1; j <= ny; j++)
			if (G[i][j] > lx[i])
				lx[i] = G[i][j];
	}
	for (int x = 1; x <= nx; x++)
	{
		for (int i = 1; i <= ny; i++)
			slack[i] = INF;
		while (true)
		{
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (dfs(x))
				break;
			int d = INF;
			for (int i = 1; i <= ny; i++)
				if (!visy[i] && d > slack[i])
					d = slack[i];
			for (int i = 1; i <= nx; i++)
				if (visx[i])
					lx[i] -= d;
			for (int i = 1; i <= ny; i++)
			{
				if (visy[i])
					ly[i] += d;
				else
					slack[i] -= d;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= ny; i++)
	{
		if (linker[i] > -1)
			res += G[linker[i]][i];
	}
	return res;
}

int main(void)
{
	int a[maxn];
	int link[maxn];
	while (scanf("%d", &ans) != EOF && ans)
	{
		for (int i = 1; i <= ans; i++)
			scanf("%d", &a[i]);
		nx = ny = 0;
		for (int i = 1; i <= ans; i++)
			if (a[i] == 0)
				link[++ny] = i;
		memset(G, 0, sizeof(G));
		for (int i = 1; i <= ans; i++)
		{
			if (a[i] > 1)
			{
				for (int k = 1; k < a[i]; k++)
				{
					nx++;
					for (int j = 1; j <= ny; j++)
						G[nx][j] = -min(abs(link[j] - i), ans - abs(link[j] - i));
				}
			}
		}
		printf("%d\n", -KM());
	}
	return 0;
}