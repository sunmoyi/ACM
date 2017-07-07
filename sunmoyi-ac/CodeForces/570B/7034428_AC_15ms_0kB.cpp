#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long n, m, ans;

int main(void)
{
	scanf("%lld %lld", &n, &m);
	if (n == 1)
	{
		printf("%lld\n", m);
		return 0;
	}
	if (n % 2 == 1)
	{
		int mid = (n >> 1) + 1;
		if (m >= mid)
			ans = m - 1;
		else
			ans = m + 1;
	}
	else
	{
		int mid = n >> 1;
		if (m <= mid)
			ans = m + 1;
		else
			ans = m - 1;
	}
	printf("%lld\n", ans);
	return 0;
}