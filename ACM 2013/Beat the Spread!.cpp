#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	long long a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld %lld", &a, &b);
			if ((a + b) % 2 == 1 || a < b)
			{
				printf("impossible\n");
				continue;
			}
			else
			{
				printf("%lld %lld\n", (a + b) / 2, (a - b) / 2);
			}
		}
	}
	return 0;
}