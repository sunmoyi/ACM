#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[21][810];
int path[21][810];
int n, m;
int p[210], d[210], s[210], v[210], id[210];

bool select(int j, int k, int i)
{
	while (j > 0 && path[j][k] != i)
	{
		k -= v[path[j][k]];
		j--;
	}
	return j ? false : true;
}

int main(void)
{
	int icase = 1;
	while (scanf("%d %d", &n, &m) != EOF && n)
	{
		memset(dp, -1, sizeof(dp));
		memset(path, 0, sizeof(path));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &p[i], &d[i]);
			s[i] = p[i] + d[i];
			v[i] = p[i] - d[i];
		}
		int fix = m * 20;

		dp[0][fix] = 0;
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k <= 2 * fix; k++)
			{
				if (dp[j - 1][k] >= 0)
				{
					for (int i = 1; i <= n; i++)
					{
						if (dp[j][k + v[i]] < dp[j - 1][k] + s[i])
						{
							if (select(j - 1, k, i))
							{
								dp[j][k + v[i]] = dp[j - 1][k] + s[i];
								path[j][k + v[i]] = i;
							}
						}
					}
				}
			}
		}
		int k;
		for (k = 0; k <= fix; k++)
			if (dp[m][fix - k] >= 0 || dp[m][fix + k] >= 0)
				break;
		int div = dp[m][fix - k] > dp[m][fix + k] ? (fix - k) : (fix + k);
		printf("Jury #%d\n", icase++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",
			(dp[m][div] + div - fix) / 2, (dp[m][div] - div + fix) / 2);
		int i, j;
		for (i = 0, j = m, k = div; i < m; i++)
		{
			id[i] = path[j][k];
			k -= v[id[i]];
			j--;
		}
		sort(id, id + m);
		for (int i = 0; i < m; i++)
			printf(" %d", id[i]);
		printf("\n");
	}
	return 0;
}