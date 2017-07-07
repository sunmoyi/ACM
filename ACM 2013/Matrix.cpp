#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[1005][1005];
int hang[1005], lie[1005];
int ans, a, b, c;
int v, n, m;

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			for (int i = 1; i <= 1005; i++)
			{
				hang[i] = i;
				lie[i] = i;
			}
			scanf_s("%d %d %d", &a, &b, &c);
			for (int i = 1; i <= a; i++)
			{
				for (int j = 1; j <= b; j++)
				{
					scanf_s("%d", &num[i][j]);
				}
			}
			for (int i = 1; i <= c; i++)
			{
				scanf_s("%d %d %d", &v, &n, &m);
				if (v == 1)
				{
					int temp = hang[n];
					hang[n] = hang[m];
					hang[m] = temp;
				}
				if (v == 2)
				{
					int temp = lie[n];
					lie[n] = lie[m];
					lie[m] = temp;
				}
				if (v == 3)
				{
					for (int j = 1; j <= b; j++)
					{
						num[hang[n]][lie[j]] += m;
					}
				}
				if (v == 4)
				{
					for (int j = 1; j <= a; j++)
					{
						num[hang[j]][lie[n]] += m;
					}
				}
			}

			for (int i = 1; i <= a; i++)
			{
				printf("%d", num[hang[i]][lie[1]]);
				for (int j = 2; j <= b; j++)
				{
					printf(" %d", num[hang[i]][lie[j]]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}