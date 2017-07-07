#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

long long l, n;
long long len[1000];

long long cmp(long long a, long long b)
{
	return a > b;
}
int main(void)
{
	while (scanf_s("%lld %lld", &l, &n) != EOF)
	{
		memset(len, 0, sizeof(len));
		for (long long i = 0; i < n; i++)
			scanf_s("%lld", &len[i]);
		sort(len, len + n, cmp);
		long long i = 0;
		while (l)
		{
			if (l > len[i])
				l -= len[i];
			else
				l = 0;
			i++;
			if (i == n)
				break;
		}
		if (i == n)
			printf("impossible\n");
		else
			printf("%lld\n", i);
	}
	return 0;
}