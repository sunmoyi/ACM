#include<cstdio>
#include<cstring>

using namespace std;

long long  gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long gcd2(long long a, long long b)
{
	int temp = 0;
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

long long lcm(long long a, long long b)
{                       
	return a * b / gcd(a, b);
}
