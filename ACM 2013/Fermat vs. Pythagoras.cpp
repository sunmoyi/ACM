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
	int temp, m, n, i, ans1, ans2, x, y, z;
	ans1 = ans2 = 0;
	memset(flag, false, sizeof(flag));
	temp = sqrt(t * 1.0);
	for (n = 1; n <= temp; n++)
	{
		for (m = n + 1; m <= temp; m++)
		{
			if (m * m + n * n > t)
				break;
			if (n % 2 != m % 2)
			{
				if (gcd(n, m) == 1)
				{
					x = m * m - n * n;
					y = m * n * 2;
					z = m * m + n * n;
					ans1++;
					for (i = 1;; i++)
					{
						if (i * z > t)
							break;
						flag[i * x] = true;
						flag[i * y] = true;
						flag[i * z] = true;
					}
				}
			}
		}
	}
	for (i = 1; i <= t; i++)
		if (!flag[i])
			ans2++;
	printf("%d %d\n", ans1, ans2);
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