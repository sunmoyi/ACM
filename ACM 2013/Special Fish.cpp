#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110
#define INF 0xfffffff

using namespace std;

int nx, ny;
int G[maxn][maxn];
int linker[maxn], lx[maxn], ly[maxn];
int slack[maxn];
bool visx[maxn], visy[maxn];
int ans, price[maxn];;

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
			if (G[i][j] > lx[i])
				lx[i] = G[i][j];
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
	char c[maxn];
	while (scanf("%d", &ans) != EOF && ans)
	{
		nx = ny = ans;
		for (int i = 0; i < ans; i++)
			scanf("%d", &price[i]);

		for (int i = 0; i < ans; i++)
		{
			scanf("%s", c);
			for (int j = 0; j < ans; j++)
			{
				if (c[j] == '1')
					G[i][j] = price[i] ^ price[j];//!!!!!!!mark
				else
					G[i][j] = 0;
			}
		}
		printf("%d\n", KM());
	}
	return 0;
}