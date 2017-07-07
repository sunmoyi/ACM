#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 17

using namespace std;

int d[1 << N][N], dist[N][N];
int n, i, j, S, ans;
bool f;

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &dist[i][j]);
	
	n -= 2;
	for (int i = 0; i < n; i++)
		d[(i << i)][i] = dist[0][i + 1];

	for (S = 0; S < (1 << n); S++)
	{
		for (int i = 0; i < n; i++)
			if (S == (1 << i))
				f = true;
		if (f)
		{
			f = false;
			continue;
		}
		for (int i = 0; i < n; i++)
			d[S][i] = INT32_MAX / 2;
		for (int i = 0; i < n; i++)
		{
			if (S & (1 << i))
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j)
						continue;
					if (S & (1 << j))
						d[S][i] = min(d[S][i], d[S - (1 << i)][j] + dist[j + 1][i + 1]);
				}
			}
		}
	}
	ans = INT_MAX / 2;
	S = (1 << n) - 1;
	for (int i = 0; i < n; i++)
		ans = min(ans, d[S][i] + dist[i + 1][n + 1]);
	printf("%d\n", ans);
	return 0;
}