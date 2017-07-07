#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long a, b, c, d, e;

int main(void)
{
	int num;
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			d = a * 1001 * 1001 + b * 1001 + c;
			scanf("%lld %lld %lld", &a, &b, &c);
			e = a * 1001 * 1001 + b * 1001 + c;
			if (d > e)
				printf("First\n");
			else if (d < e)
				printf("Second\n");
			else
				printf("Same\n");
		}
	}
	return 0;
}