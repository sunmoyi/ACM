#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 10000001

using namespace std;

bool flag[N];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void solve(int t)
{
	int temp, m, n, i, ans, x, y, z;
	ans = 0;
	memset(flag, false, sizeof(flag));
	temp = sqrt(t + 0.0);
	for (n = 1; n <= temp; n++)
	{
		for (m = n + 1; m <= temp; m++)
		{
			if (2 * m * m + 2 * m * n > t)
				break;
			if (n % 2 != m % 2)
			{
				if (gcd(m, n) == 1)
				{
					x = m * m - n * n;
					y = 2 * m * n;
					z = m * m + n * n;
					for (i = 1; ; i++)
					{
						if (i * (x + y + z) > t)
							break;
						ans++;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		solve(n);
	}
	return 0;
}