#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, num[1010];
long long sumtime;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);

		sort(num + 1, num + 1 + n);

		int temp1 = n / m;
		int temp2 = n % m;

		long long kk[1010];
		memset(kk, 0, sizeof(kk));

		for (int i = m + 1; i <= n; i++)
		{
			for (int j = (i % m); j < i; j += m)
				kk[i % m] += num[j];
			//kk[i % m] *= 2;
			//kk[i % m] += num[i - m];
		}
		sumtime = 0;
		for (int i = 0; i < m; i++)
			sumtime += kk[i];
		printf("%lld\n", sumtime);
	}
	return 0;
}