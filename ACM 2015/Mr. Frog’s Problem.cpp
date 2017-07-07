#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
long long a, b;

int main (void)
{
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%lld %lld", &a, &b);
		printf("Case #%d:\n", t);
		if (a == b)
		{
			printf("1\n");
			printf("%lld %lld\n", a, b);
		}
		else
		{
			printf("2\n");
			if (a < b)
			{
				printf("%lld %lld\n", a, b);
				printf("%lld %lld\n", b, a);
			}
			else
			{
				printf("%lld %lld\n", b, a);
				printf("%lld %lld\n", a, b);
			}
		}
	}
	return 0;
}