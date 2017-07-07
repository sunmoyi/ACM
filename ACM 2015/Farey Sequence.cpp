#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long a[100000000];

void phi()
{
	for (int i = 1; i <= 1000005; i++)
		a[i] = i;
	for (int i = 2; i <= 1000001; i += 2)
		a[i] /= 2;
	for (int i = 3; i <= 1000001; i += 2)
	{
		if (a[i] == i)
		{
			for (int j = i; j <= 1000001; j += i)
				a[j] = a[j] / i * (i - 1);
		}
	}
	for (int i = 3; i <= 1000001; i++)
	{
		a[i] += a[i - 1];
	}
}

int main(void)
{
	phi();
	long long n;
	while (scanf("%lld", &n) != EOF && n)
	{
		printf("%lld\n", a[n]);
	}
	return 0;
}