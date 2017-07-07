#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	long long mxh, mcj, xh, a[105];
	int cj;
	while (scanf("%lld", &mxh) != EOF)
	{
		memset(a, 0, sizeof(a));
		while (1)
		{
			scanf("%lld %d", &xh, &cj);
			if (xh == 0 && cj == 0)
				break;
			a[cj]++;
			if (xh == mxh)
				mcj = cj;
		}
		long long sum = 0;
		for (int i = 100; i > mcj; i--)
			sum += a[i];
		printf("%lld\n", sum + 1);
	}
	return 0;
}