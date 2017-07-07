#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 55

using namespace std;

int num[maxn][maxn];//i划分为k个正整数之和
int num2[maxn][maxn];//划分成若干个不同的正整数之和
int f[maxn][maxn];//划分成若干个奇正整数之和
int g[maxn][maxn];

void init()
{
	int i, j;
	for (int i = 1; i < maxn; i++)
		num[i][0] = num[0][i] = num2[i][0] = num2[0][i] = 0;
	for (int i = 1; i < maxn; i++)
	{
		for(int j = 1; j < maxn; j++)
		{
			if (i < j)
				num[i][j] = 0;
			else if (i == j)
				num[i][j] = 1;
			else//           最小划分结果是1       不含一
				num[i][j] = num[i - 1][j - 1] + num[i - j][j];
		}
	}
	f[0][0] = 1, g[0][0] = 1;
	for (i = 1; i < maxn; i++)
	{
		for (j = 1; j <= i; j++)
		{
			g[i][j] = f[i - j][j];
			f[i][j] = f[i - 1][j - 1] + g[i - j][j];
		}
	}
}

long long fun2(int n, int m)//计算将n进行划分， 最大的划分结果不大于m
{
	if (n == 1 || m == 1)
		return 1;
	else if (n < m)
		return fun2(n, n);
	else if (n == m)
		return (1 + fun2(n, m - 1));
	else
		return (fun2(n, m - 1) + fun2(n - m, m));
}

int fun(int n, int m)//计算将n进行划分， 最大的划分结果小于m
{
	if (n == 1 && m == 1)
		return 1;
	else if (m == 1)
		return 0;
	else if (n < m)
		return fun(n, n);
	else if (n == m)
		return (1 + fun(n, m - 1));
	else
		return (fun(n, m - 1) + fun(n - m, m - 1));
}

int main(void)
{
	init();
	int n, m, res;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		printf("%d\n", num[n][m]);
		printf("%d\n", fun(n, n));	
		printf("%lld\n", fun2(n, n));
		res = 0;
		for (int i = 1; i <= n; i++)
			res += f[n][i];
		printf("%d\n", res);
	}
	return 0;
}