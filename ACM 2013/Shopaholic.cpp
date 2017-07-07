#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, a[100000];

bool cmp(int x, int y)
{
	return x > y;
}

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		while (n--)
		{
			scanf("%d", &m);
			for (int i = 1; i <= m; i++)
				scanf("%d", &a[i]);
			int sum = 0;
			sort(a + 1, a + m + 1, cmp);
			int k = m / 3;
			for (int i = 1; i <= k; i++)
				sum += a[i * 3];
			printf("%d\n", sum);
		}
	}
	return 0;
}