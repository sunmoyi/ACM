#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10005][105];
int  i, j, k, l, num, n, m, v, t;

int compear(int a, int b)
{
	return a > b;
}
int main(void)
{
	int count[10010];

	while (scanf_s("%d %d %d", &n, &m, &v) != EOF)
	{
		num = 0;
		memset(count, 0, sizeof(count));
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				scanf_s("%d", &a[i][j]);
				if (a[i][j] == 0)
					num++;
			}
		}
		for (i = m; i >= 1; i--)
		{
			if (a[n][i] == 0)
				num--;
			else
				break;
		}
		num -= v * 2;
		k = 0;
		for (i = 2; i <= n; i++)
		{
			t = 0;
			if (a[i][1] == 0 && a[i][2] == 0)
			{
				for (j = m; j >= 1; j--)
				{
					if (a[i - 1][j] == 0)
						t++;
					else
						break;
				}
				count[k++] = t;
			}
		}
		count[k] = 0;
		sort(count, count + k - 1, compear);
		for (i = 0; i < v - 1; i++)
			num -= count[i];
		printf("%d\n", num);
	}
	return 0;
}