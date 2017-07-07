#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void)
{
	long long kk = (1 << 17) - 1;
	printf("%lld\n", kk);

	long long sum = 0;
	for (int i = 1; i <= 16; i++)
	{
		long long k = 1 << (i);
		long long kk = k * (17 - i);
		sum += kk;
	}
	printf("%lld\n", sum);
	return 0;
}