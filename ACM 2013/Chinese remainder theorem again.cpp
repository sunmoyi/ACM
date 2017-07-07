#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
	int n, k;
	int temp;
	long long ans;
	while (scanf("%d %d", &n, &k) != EOF && (n + k))
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &temp);
			ans = ans * temp / gcd(ans, temp);
		}
		printf("%lld\n", ans - k);
	}
	return 0;
}