#include<cstdio>
#include<algorithm>

using namespace std;

long long a[505], b[505], c[505];
long long l, n, m, s, t;
long long ans;
long long sum[505 * 505];

bool find(long long t)
{
	for (int i = 1; i <= m; i++)
	{

		long long l = 1, u = ans - 1;
		while (l <= u)
		{
			long long mid = (l + u) / 2;
			if (sum[mid] == t - c[i])
			{
				return true;
			}
			else if (sum[mid] > t - c[i])
				u = mid - 1;
			else
				l = mid + 1;
		}

	}
	return false;
}

int main(void)
{
	int kk = 1;
	while (scanf_s("%lld %lld %lld", &l, &n, &m) != EOF)
	{
		printf("Case %d:\n", kk++);
		for (int i = 1; i <= l; i++)
			scanf_s("%lld", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf_s("%lld", &b[i]);
		for (int i = 1; i <= m; i++)
			scanf_s("%lld", &c[i]);

		ans = 1;
		for (long long i = 1; i <= l; i++)
			for (long long j = 1; j <= n; j++)
				sum[ans++] = a[i] + b[j];

		sort(sum + 1, sum + ans);
		sort(c + 1, c + m + 1);

		scanf_s("%lld", &s);
		while (s--)
		{
			scanf_s("%lld", &t);
			if (t < sum[1] + c[1] || t > sum[ans - 1] + c[m])
				printf("NO\n");
			else if (find(t))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}