#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double ans = 0;
int k = 0;

int main (void)
{
	while (scanf("%d", &k) != EOF && k != 0)
	{
		ans = 0;
		ans += 1 * k;
		for (int i = 2; i <= k; i++)
		{
			ans += (1.0 / i) * (k + 1 - i) * 2;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}