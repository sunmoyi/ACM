#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int n, t, v, pi;
int a[105];

int main(void)
{
	while (scanf_s("%d", &t) != EOF)
	{
		while (t--)
		{
			int maxx = 0;
			double pii = 0;
			double piii = 0;
			memset(a, 0, sizeof(a));
			scanf_s("%d %d %d", &n, &v, &pi);
			for (int i = 1; i <= n; i++)
				scanf_s("%d", &a[i]);
			sort(a + 1, a + n + 1);
			int i;
			for (i = 1; i <= n; i++)
			{
				piii = (maxx * pii + v * a[i]) * 1.0 / (maxx + v) * 1.0;
				if (piii > pi)
				{
					printf("%d %.2lf\n", maxx, pii / 100);
					break;
				}
				else
				{
					maxx += v;
					pii = piii;
				}
			}
			if (i == n + 1)
				printf("%d %.2lf\n", maxx, pii / 100);
		}
	}
	return 0;
}