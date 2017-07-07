#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m, a[105];
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum + 10 * (n - 1) > m)
			printf("-1\n");
		else
		{
			printf("%d\n", (m - sum) / 5);
		}
	}
	return 0;
}
