#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool isprime[500000];
int prime[200000];

void prim()
{
	memset(isprime, false, sizeof(isprime));
	isprime[0] = isprime[1] = true;
	int k = 0;
	for (int i = 2; i < 50000; i++)
	{
		if (isprime[i] == false)
			prime[k++] = i;
		for (int j = 2; j * i < 50000; j++)
			isprime[j * i] = true;
	}
}

int phi(int n)
{
	int rea = n;
	for (int i = 0; prime[i] * prime[i] < 500000; i++)
	{
		if (n % prime[i] == 0)
		{
			rea = rea - rea / prime[i];
			while (n % prime[i] == 0)
				n /= prime[i];
		}
	}
	if (n > 1)
		rea = rea - rea / n;
	return rea;
}

int main(void)
{
	prim();
	for (int i = 1; i <= 10000; i++)
	{
		printf("%d %d\n", i, phi(i));
	}
	return 0;
}