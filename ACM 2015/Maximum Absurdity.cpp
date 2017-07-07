#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200010

using namespace std;

long long a[maxn], b[maxn];

int main(void)
{
	int i, j, n, k;
	long long t1, maxx, maxl, maxr, ans;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		long long temp = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &temp);
			a[i] = a[i - 1] + temp;
		}
		for (i = 0, j = 1; i <= n - k; i++, j++)
			b[j] = a[i + k] - a[i];
		maxx = ans = b[1];
		t1 = maxl = maxr = 1;
		for (i = 1; i + k <= n - k + 1; i++)
		{
			if (b[i] > ans)
			{
				ans = b[i];
				t1 = i;
			}
			if (b[i + k] + ans > maxx)
			{
				maxx = b[i + k] + ans;
				maxl = t1;
				maxr = i + k;
			}
		}
		printf("%lld %lld\n", maxl, maxr);
	}
	return 0;
}