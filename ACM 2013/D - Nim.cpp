#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long n;
long long num[1005];

int main(void)
{
	while (scanf_s("%lld", &n) != EOF && n)
	{
		for (long long i = 1; i <= n; i++)
		{
			scanf_s("%lld", &num[i]);
		}

		int ans = 0;
		for (long long i = 1; i <= n; i++)
		{
			long long s = 0;
			for (long long j = 1; j <= n; j++)
			{
				if (i != j)
					s ^= num[j];
			}
			if (num[i] > s)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}