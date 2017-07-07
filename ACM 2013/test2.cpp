#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

bool a[500000000];

int main(void)
{
	memset(a, 0, sizeof(a));
	a[1] = true;
	a[0] = true;
	for (int i = 2; i < 500000000; i++)
	{
		if (a[i] == false)
		{
			for (int j = i * 2; j < 500000000; j += i)
			{
				a[j] = true;
			}
		}
	}
	double s = 437338199;
	for (long long i = 1; i < sqrt(s); i++)
	{
		long long k = s / i;
		if (s == k * i && !a[i])
			printf("%lld\n", i);
		if (s == k * i && !a[k])
			printf("%lld\n", k);
	}
	return 0;
}

/*#include<stdio.h>
int main()
{
	__int64 a[100], num, i, n;
	while (scanf_s("%I64d", &n) != EOF)
	{
		num = 0;
		for (i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
			{
				a[num++] = i;
				while (n%i == 0)
					n = n / i;
			}
		}
		if (n>1)
			a[num++] = n;
		for (i = 0; i<num; i++)
			printf("%I64d ", a[i]);
		printf("\n");
	}
	return 0;
}*/