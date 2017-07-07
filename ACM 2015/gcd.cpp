#include<cstdio>
#include<cstring>

using namespace std;

long long  gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main (void)
{
	printf("%lld\n", gcd(137, 73));
}