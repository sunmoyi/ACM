#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num[1005];

int main(void)
{
	long long a, n, m, sum;
	while (scanf("%lld", &n) != EOF && n)
	{
		sum = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &num[i]);

		scanf("%lld", &m);

		for (int i = 1; i <= n; i++)
			if (num[i] == m)
				sum++;

		printf("%lld\n", sum);
	}
	return 0;
}