#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long summ(long long a)
{
	int s = 1;
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			int n = 1;
			do {
				a /= i;
				n *= i;
			} while (a % i == 0);
			s = s * (n * i - 1) / (i - 1);
		}
	}
	if (a > 1)
		s = s * (1 + a);
	return s;
}

int main(void)
{
	long long a, t;
	while (scanf("%lld", &t) != EOF)
	{
		while (t--)
		{
			scanf("%lld", &a);
			long long ans = summ(a);
			printf("%lld\n", ans - a);
		}
	}
	return 0;
}