#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long guanqia[1005][1005];
long long sum[1005];
long long n, m, k;
long long fin, finn;

bool cmp(long long x, long long y)
{
	return x > y;
}
int main(void)
{
	while (scanf("%lld %lld %lld", &n, &m, &k) != EOF)
	{
		memset(sum, 0, sizeof(sum));
		fin = finn = 0;
		// read
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%lld", &guanqia[i][j]);
			}
		}
		//sort
		for (int i = 1; i <= n; i++)
		{
			sort(&guanqia[i][1], &guanqia[i][m + 1], cmp);
		}
		//sum
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				sum[i] += guanqia[j][i];
			}
		}
		//sum + sum
		while (fin < k && finn < m)
		{
			fin += sum[++finn];
		}
		//print
		if (k == 0)
			printf("1\n");
		else if (finn < m)
			printf("%lld\n", finn);
		else if (finn == m && fin >= k)
			printf("%lld\n", finn);
		else
			printf("-1\n");
	}
	return 0;
}