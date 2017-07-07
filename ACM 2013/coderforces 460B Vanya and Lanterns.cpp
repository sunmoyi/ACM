#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int k[10000];
int n, l;
double maxx;

int main(void)
{
	while (scanf("%d %d", &n, &l) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &k[i]);
		}

		sort(k + 1, k + n + 1);

		maxx = (double)(k[1] - 0);
		for (int i = 2; i <= n; i++)
		{
			double s = (k[i] - k[i - 1]) / 2.0000000;
			if (s > maxx)
				maxx = s;
		}
		if (l - k[n] > maxx)
			maxx = l - k[n];

		printf("%.9lf\n", maxx);
	}
	return 0;
}