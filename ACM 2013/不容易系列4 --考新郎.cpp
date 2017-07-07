#include<stdio.h>
__int64 sum[21], f[21];
int main()
{
	int i, t, n, m;
	f[0] = 0; f[1] = 0; f[2] = 1;
	sum[0] = 1; sum[1] = 1;
	for (i = 2; i <= 20; i++)
	{
		sum[i] = sum[i - 1] * i;
		if (i >= 3)
			f[i] = (i - 1)*(f[i - 1] + f[i - 2]);
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		printf("%I64d\n", sum[n] / sum[m] / sum[n - m] * f[m]);
	}
	return 0;
}