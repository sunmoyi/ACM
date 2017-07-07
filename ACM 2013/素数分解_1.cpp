#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100
using namespace std;

int factor[N], ct;

void divide(int n)
{
	int i;
	ct = 0;
	for (i = 2; i <= sqrt(n + 0.0); i++)
	{
		while (n % i == 0)
		{
			ct++;
			factor[ct] = i;
			n /= i;
		}
	}
	if (n != 1)
	{
		ct++;
		factor[ct] = n;
	}
}

int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		divide(n);
		for (int i = 1; i <= ct; i++)
			printf("%d\n", factor[i]);
	}
	return 0;
}