#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define maxn 10000

using namespace std;

int prime[maxn + 10], nprime;
bool isprime[maxn + 10];
int factor[maxn + 10], ct;

void make_prime()
{
	int j;
	nprime = 0;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = 0;
	for (int i = 2; i <= sqrt(maxn - 1.0); i++)
	{
		//printf("%d\n", i);
		if (isprime[i])
		{
			nprime++;
			prime[nprime] = i;
			for (j = i * i; j <= maxn; j += i)
			{
				isprime[j] = false;
			}
		}
	}
}

void divide(int n)
{
	int temp = (int)sqrt(n + 0.0);
	for (int i = 1; i <= temp; i++)
	{
		if (prime[i] > temp)
			break;
		while (n % prime[i] == 0)
		{
			ct++;
			factor[ct] = prime[i];
			n /= prime[i];
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
	int a;
	make_prime();
	while (scanf("%d", &a) != EOF)
	{
		ct = 0;
		divide(a);
		for (int i = 1; i <= ct; i++)
			printf("%d ", factor[i]);
		printf("\n");
	}
	return 0;
}