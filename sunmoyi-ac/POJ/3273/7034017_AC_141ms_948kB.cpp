#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

long long n, m;
long long money[maxn];

bool check(long long x)
{
	long long temp = 0;
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		temp += money[i];
		if (temp > x)
		{
			i--;
			temp = 0;
			ans++;
		}
		if (ans > m)
			return false;
	}
	if (ans <= m)
		return true;
	else
		return false;
}

int main(void)
{
	while (scanf("%lld %lld", &n, &m) != EOF)
	{
		long long sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &money[i]);
			sum += money[i];
		}

		long long left = 1, right = sum;
		while (left < right)
		{
			long long mid = (left + right) >> 1;
			if (check(mid))
				right = mid;
			else
				left = mid + 1;
		}
		printf("%lld\n", right)   ;
	}
	return 0;
}