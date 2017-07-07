#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int k, l, m, d, n;
	while (scanf("%d %d %d %d %d", &k, &l, &m, &d, &n) != EOF)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i % k == 0 || i % l == 0 || i % m == 0
				|| i % d == 0)
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}