#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char num[3000005];

int sum(char a)
{
	return a - '0';
}

int main(void)
{
	while (scanf("%s", num) != EOF)
	{
		long long len = strlen(num);
		long long ans = 0;
		long long kk = 0;
		long long k = 0;
		for (long long i = 0; i < len; i++)
		{
			if (i == 0)
			{
				if (sum(num[0]) % 4 == 0)
					ans++;
			}
			else
			{
				kk = sum(num[i]) + sum(num[i - 1]) * 10;
				if (kk % 4 == 0)
					ans += (i);
				k = sum(num[i]);
				if (k % 4 == 0)
					ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}