#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100001

using namespace std;

void divide(int n)
{
	int i, ct = 0, factor[N];
	for (i = 2; i <= sqrt(n + 0.0); i++)
	{
		while (n % i == 0)
		{
			ct++;
			factor[ct] = i;
			if (ct != 1)
				printf("*");
			printf("%d", factor[ct]);
			n /= i;
		}
	}
	if (n != 1)
	{
		ct++;
		factor[ct] = n;
		if (ct != 1)
			printf("*");
		printf("%d", n);
	}
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		divide(n);
		printf("\n");
	}
	return 0;
}