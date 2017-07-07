#include<cstdio>

using namespace std;

int no_4_62(long n)
{
	while (n)
	{
		if (n % 10 == 4 || n % 100 == 62)
			return 0;
		n /= 10;
	}
	return 1;
}

int a[1000001] = { 0 };

int main()
{
	long n, m, i;
	for (i = 1; i<1000001; i++)
		a[i] = a[i - 1] + no_4_62(i);

	while (scanf("%ld%ld", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		printf("%d\n", a[m] - a[n - 1]);
	}
	return 0;
}
