#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 10001

using namespace std;

int prime[N], nprime;
bool isprime[N];

void make_prime(int n)
{
	int i, j;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for (i = 2; i < n; i++)
	{
		if (isprime[i])
		{
			nprime++;
			prime[nprime] = i;
			for (j = i * i; j < n; j += i)
			{
				isprime[j] = false;
			}
		}
	}
}

void divide(int n)
{
	int i, ct = 0, factor[N];
	int temp = sqrt(n + 0.0);
	for (i = 1; i <= nprime; i++)
	{
		if (prime[i] > temp)
			break;
		while (n % prime[i] == 0)
		{
			ct++;
			factor[ct] = prime[i];
			n /= prime[i];
			if (ct != 1)
				printf("*");
			printf("%d", prime[i]);
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
	make_prime(N - 1);
	while (scanf("%d", &n) != EOF)
	{
		divide(n);
		printf("\n");
	}
	return 0;
}