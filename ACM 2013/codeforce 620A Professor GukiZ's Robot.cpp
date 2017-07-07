#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void)
{
	long long a, b, c, d;
	while (scanf_s("%lld", &a) != EOF)
	{
		scanf_s("%lld %lld %lld", &b, &c, &d);
		long long maxx = max(abs(a - c), abs(b - d));

		printf("%lld\n", maxx);
	}
	return 0;
}