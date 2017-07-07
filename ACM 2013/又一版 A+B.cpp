#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	long long a, b, c;
	while (scanf("%lld", &a) != EOF && a != 0)
	{
		scanf("%lld %lld", &b, &c);
		long long d = b + c;
		long long e = 0;
		int i = 0;
		while (d > 0)
		{
			e += (d % a) * pow(10, i++);
			d /= a;
		}
		printf("%lld\n", e);
	}
	return 0;
}