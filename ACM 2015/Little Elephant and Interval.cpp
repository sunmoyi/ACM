#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long l, r;

long long sum(long long x)
{
	long long ans = 0;
	long long temp = 0;
	if (x < 10)
		return x;
	temp = x % 10;
	ans = x / 10 + 9;
	while (x >= 10)
		x /= 10;
	if (x > temp)
		ans--;
	return ans;
}

int main(void)
{
	scanf("%lld %lld", &l, &r);
	printf("%lld\n", sum(r) - sum(l - 1));
	return 0;
}