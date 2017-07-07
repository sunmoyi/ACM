#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5000000
using namespace std;

bool isprimer[N];
int primer[N], nprimer;

void doprimer()
{
	long long i, j;
	nprimer = 0;
	memset(isprimer, true, sizeof(isprimer));
	isprimer[1] = 0;
	for (i = 2; i < N; i++)
	{
		if (isprimer[i])
		{
			primer[++nprimer] = i;
			for (j = i * i; j < N; j += i)
				primer[j] = false;
		}
	}
}

bool isp(int n)
{
	int i, k = (int)sqrt(double(n));
	for (i = 1; primer[i] <= k; i++)
		if (n % primer[i] == 0)
			return 0;
	return 0;
}
int main(void)
{
	long long n;
	while (scanf("%lld", &n) != EOF)
	{
		if (n == 1)
			printf("NO\n");
		else if (isp(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}