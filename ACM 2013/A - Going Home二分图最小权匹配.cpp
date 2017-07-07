#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 210
#define INF 0xfffffff

using namespace std;

struct node {
	int x, y;
}house[maxn], man[maxn];
int numhouse, numman;
int nx, ny;
int G[maxn][maxn];
int linker[maxn], lx[maxn], ly[maxn];
int slack[maxn];
bool visx[maxn], visy[maxn];
int n, m;

bool dfs(int x)
{
	visx[x] = true;
	for (int y = 0; y < ny; y++)
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
				return true;
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
	for (int i = 0; i < nx; i++)
	{
		lx[i] = -INF;
		for (int j = 0; j < ny; j++)
		{
			if (G[i][j] > lx[i])
				lx[i] = G[i][j];
		}
	}
	for (int x = 0; x < nx; x++)
	{
		for (int i = 0; i < ny; i++)
			slack[i] = INF;
		while (true)
		{
			memset(visx, false, sizeof(visx));
			memset(visy, false, sizeof(visy));
			if (dfs(x))
				break;
			int d = INF;
			for (int i = 0; i < ny; i++)
				if (!visy[i] && d > slack[i])
					d = slack[i];
			for (int i = 0; i < nx; i++)
				if (visx[i])
					lx[i] -= d;
			for (int i = 0; i < ny; i++)
			{
				if (visy[i])
					ly[i] += d;
				else
					slack[i] -= d;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < ny; i++)
		if (linker[i] != -1)
			res += G[linker[i]][i];
	return res;
}

int main(void)
{
	char c;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		numhouse = numman = 0;
		memset(G, 0, sizeof(G));
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &c);
				if (c == 'm')
				{
					man[numman].x = i;
					man[numman].y = j;
					numman++;
				}
				else if (c == 'H')
				{
					house[numhouse].x = i;
					house[numhouse].y = j;
					numhouse++;
				}
			}
		}
		for (int i = 0; i < numman; i++)
		{
			for (int j = 0; j < numhouse; j++)
			{
				G[i][j] = -(abs(man[i].x - house[j].x) + abs(man[i].y - house[j].y));
			}
		}
		nx = numman;
		ny = numhouse;
		printf("%d\n", -KM());
	}
	return 0;
}