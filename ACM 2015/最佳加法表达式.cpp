#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num[110][110];
int number[100];
long long mark[100][100];

long long V(int n, int m)//n个数  m个加号
{
	//printf("%d %d\n", n, m);
	if (m == 0)
		return num[1][n];
	else if (n == 0)
		return 0xfffffff;
	else
	{
		if (mark[n][m] != 0)
			return mark[n][m];
		long long fin = 0xfffffff;
		for (int i = m; i <= n - 1; i++)
			fin = min(fin, V(i, m - 1) + num[i + 1][n]);
		mark[n][m] = fin;
		return fin;
	}
}

int main(void)
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)//n个数， m个加号
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &number[i]);
		for (int i = 1; i <= n; i++)
		{
			num[i][i] = number[i];
			for (int j = i + 1; j <= n; j++)
			{
				num[i][j] = num[i][j - 1] * 10 + number[j];
				//printf("%d %d %lld\n", i, j, num[i][j]);
			}
		}
		memset(mark, 0, sizeof(mark));
		printf("%lld\n", V(n, m));
	}
	return 0;
}