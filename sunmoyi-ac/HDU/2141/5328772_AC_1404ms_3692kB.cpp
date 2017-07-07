#include<cstdio>  
#include<algorithm>  
#include<cstring>  
using namespace std;

long long a[505], b[505], c[505], la, lb, lc;
long long sum[505 * 505], len;

bool bin(long long x)
{
	long long l = 0, u = len - 1;
	while (l <= u)
	{
		long long mid = (l + u)/ 2;
		if (sum[mid] == x)
			return true;
		else if (sum[mid] > x)
			u = mid - 1;
		else
			l = mid + 1;
	}
	return false;
}

int main()
{
	long long m, s, cas = 1, i, j, k;
	while (scanf_s("%lld%lld%lld", &la, &lb, &lc) != EOF)
	{
		printf("Case %lld:\n", cas++);
		for (i = 0; i<la; i++)
			scanf_s("%lld", &a[i]);
		for (i = 0; i<lb; i++)
			scanf_s("%lld", &b[i]);
		for (i = 0; i<lc; i++)
			scanf_s("%lld", &c[i]);

		sort(c, c + lc);

		len = 0;
		for (i = 0; i<la; i++)
		{
			for (j = 0; j<lb; j++)
			{
				sum[len++] = a[i] + b[j];
			}
		}

		sort(sum, sum + len);

		scanf_s("%lld", &m);
		while (m--)
		{
			scanf_s("%lld", &s);
			if (s>sum[len - 1] + c[lc - 1] || s<sum[0] + c[0])
			{
				printf("NO\n");
				continue;
			}

			long long flag = 0;
			for (i = 0; i<lc; i++)
			{
				int kk = s - c[i];
				if (bin(kk))
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}