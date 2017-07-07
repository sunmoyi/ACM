#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long len;
long long k[80000000];
long long sum;

int main(void)
{
	while (scanf("%lld", &len) != EOF)
	{
		sum = 0;
		for (long long i = 1; i <= len; i++)
			scanf("%lld %lld", &k[i * 2 - 1], &k[i * 2]);
		long long flag = 1;
		for (long long i = 1; i <= len * 2; i++)
		{
			if (k[i] == 6)
			{
				if (i - (flag * 2 - 1) > 0)
					sum += (i - (flag * 2 - 1));
				flag++;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}