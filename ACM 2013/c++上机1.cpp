#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

bool prime[1005];

int main(void)
{
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= sqrt(1005.0); i++)
	{
		for (int j = 2; i * j < 1005; j++)
		{
			prime[i * j] = true;
		}
	}

	int num = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (!prime[i])
		{
			printf("%d\t", i);
			num++;
		}
	}
	printf("\ntotal: %d\n", num);
	return 0;
}