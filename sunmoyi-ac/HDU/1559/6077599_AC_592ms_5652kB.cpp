#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005

using namespace std;

int num[maxn][maxn];
int N, M;
int x, y, k, summ = 0;

int lowbit(int x)
{
	return x & (-x);
}

void add(int x, int y, int delta)
{
	for (int i = x; i <= N; i += lowbit(i))
	{
		for (int j = y; j <= M; j += lowbit(j))
		{
			num[i][j] += delta;
		}
	}
}

int sum(int x, int y)
{
	int res = 0;
	for (int i = x; i > 0; i -= lowbit(i))
	{
		for (int j = y; j > 0; j -= lowbit(j))
		{
			res += num[i][j];
		}
	}
	return res;
}

void init()
{
	int i, j;
	for (i = 0; i <= N; i++)
		for (j = 0; j <= M; j++)
			num[i][j] = 0;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		summ = 0;
		scanf("%d %d %d %d", &N, &M, &x, &y);
		init();

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				scanf("%d", &k);
				add(i, j, k);
			}
		}
		for (int i = 1; i + x - 1 <= N; i++)
		{
			for (int j = 1; j + y - 1 <= M; j++)
			{
				int temp = sum(i + x - 1, j + y - 1) - sum(i - 1, j + y - 1) - sum(i + x - 1, j - 1) + sum(i - 1, j - 1);
				summ = max(summ, temp);
			}
		}
		printf("%d\n", summ);
	}
	return 0;
}