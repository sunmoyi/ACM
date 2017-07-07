#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num[14];
long long page;

int main (void)
{
	while (scanf("%lld", &page) != EOF)
	{
		memset(num, 0, sizeof(num));
		for (long long i = 1; i <= page; i++)
		{
			long long a = i;
			while (a)
			{
				num[a % 10]++;
				a /= 10;
			}
			if (i % 1000000 == 0)
				printf("%lld\n", i);
		}
		for (int i = 0; i <= 9; i++)
			printf("%lld\n", num[i]);
	}
	return 0;
}