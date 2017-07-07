#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, a[100000005], ans, sum;

int main(void)
{
	while (scanf_s("%d", &n) != EOF && n)
	{
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			sum = 0;
			for (int j = 1; j <= n; j++)
			{
				if (i != j)
				{
					sum ^= a[j];
				}
			}
			if (sum < a[i])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}