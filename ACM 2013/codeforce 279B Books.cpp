#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
int a[1000005];

int main(void)
{
	
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		int sum = 0;
		int ans = 0;
		int maxx = 0;
		int start = 1, endd = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d", &a[i]);
			sum += a[i];
			if (sum > m)
			{
				endd = i - 1;
				ans = endd - start + 1;
				maxx = max(ans, maxx);
			}
			else if (i == n)
			{
				endd = n;
				ans = n - start + 1;
				maxx = max(ans, maxx);
			}
			while (sum > m)
			{
				sum -= a[start++];
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}