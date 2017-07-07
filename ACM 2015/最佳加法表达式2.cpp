#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num[110][110];
int number[100];
long long mark[100][100];

long long V(int n, int m)
{
	if (n == 0)
		return 999999999;
	else if (m == 0)
		return num[1][n];
	else
	{
		if (mark[n][m])
			return mark[n][m];
		long long fin = 999999999;
		for (int i = m; i <= n - 1; i++)
			fin = min(fin, V(i, m - 1) + num[i + 1][n]);
		mark[n][m] = fin;
		return fin;
	}
}

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &number[i]);
		for (int i = 1; i <= n; i++)
		{
			num[i][i] = number[i];
			for (int j = i + 1; j <= n; j++)
				num[i][j] = num[i][j - 1] * 10 + number[j];
		}
		memset(mark, 0, sizeof(mark));
		printf("%d\n", V(n, m));
	}
	return 0;
}