#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 510
#define INF 0x3f3f3f3f

using namespace std;

int h, w, q;
char val[maxn][maxn];
int sumrow[maxn][maxn];
int sumcol[maxn][maxn];

void input(void)
{
	scanf("%d %d", &h, &w);

	for (int i = 1; i <= h; i++)
	{
		scanf("%s", val[i] + 1);
		for (int j = 1; j <= w; j++)
		{
			if (val[i][j] == '.' && val[i][j - 1] == '.')
				sumrow[i][j] = 1 + sumrow[i][j - 1];
			else
				sumrow[i][j] = sumrow[i][j - 1];
		}
	}
	for (int j = 1; j <= w; j++)
	{
		for (int i = 1; i <= h; i++)
		{
			if (val[i][j] == '.' && val[i - 1][j] == '.')
				sumcol[i][j] = sumcol[i - 1][j] + 1;
			else
				sumcol[i][j] = sumcol[i - 1][j];
		}
	}
}

void solve(void)
{
	int r1, c1, r2, c2;
	scanf("%d", &q);
	long long res = 0;
	for (int i = 1; i <= q; i++)
	{
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		res = 0;
		for (int j = r1; j <= r2; j++)
			res += sumrow[j][c2] - sumrow[j][c1];
		for (int j = c1; j <= c2; j++)
			res += (sumcol[r2][j] - sumcol[r1][j]);
		printf("%lld\n", res);
	}
}

int main(void)
{
	input();
	solve();

	return 0;
}