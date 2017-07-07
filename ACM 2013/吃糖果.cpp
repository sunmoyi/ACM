#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long  num[1000005];

int main(void)
{
	long long n, m;
	while (scanf("%lld", &n) != EOF)
	{
		while (n--)
		{
			long long maxx = 0;
			long long sum = 0;
			scanf("%lld", &m);
			for (long long i = 1; i <= m; i++)
			{
				scanf("%lld", &num[i]);
				if (maxx < num[i])
				{
					sum += maxx;
					maxx = num[i];
				}
				else
				{
					sum += num[i];
				}
			}
			if (maxx > sum + 1)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}