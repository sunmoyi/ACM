#include<stdio.h>
#include<string.h> 
#define INF 999999999 

long long sum[100005], p[100005];

int main()
{
	int i, j, n, m;
	long long a;
	while (scanf("%d", &n) != EOF)
	{
		memset(sum, 0, sizeof(sum));
		memset(p, 0, sizeof(p));
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &a);
			sum[i] = sum[i - 1] + a;
		}
		scanf("%d", &m);
		int beg = 0, end = 0;
		long long maxnum = -INF;
		for (i = 1; i <= n; i++)
		{
			while (p[beg]<i - m)
				beg++;
			while (sum[p[end]] >= sum[i] && end >= beg)
				end--;
			end++;
			if (sum[i] - sum[p[beg]]>maxnum)
				maxnum = sum[i] - sum[p[beg]];
			p[end] = i;
		}
		printf("%lld\n", maxnum);
	}
	return 0;
}