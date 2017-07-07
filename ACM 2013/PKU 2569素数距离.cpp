/*
 *给定下限L， 和上线U 求[l, u]中相邻素数的差的最大值和最小值
 *先用素数筛 筛出1 - sqrt（max）的素数
 *然后判断[l, u]之间的素数 依次扫面出来距离
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 9999999
#define N 500001
using namespace std;

int prime1[N], nprime1;
bool isprime[N * 20];

void make_prime1()
{
	long long i, j;
	nprime1 = 0;
	memset(isprime, 1, sizeof(isprime));
	for (i = 2; i < N; i++)
	{
		if (isprime[i])
		{
			nprime1++;
			prime1[nprime1] = i;
			for (j = i * i; j < N; j += i)
			{
				isprime[j] = 0;
			}
		}
	}
}

long long l, u;
long long prime2[1000001];
int nprime2;

void make_prime2()
{
	long long i, j, b;
	memset(isprime, 1, sizeof(isprime)); 
	for (int i = 1; i <= nprime1; i++)
	{
		b = l / prime1[i];
		while (b * prime1[i] < l || b <= 1)
			b++;
		for (j = b * prime1[i]; j <= u; j++)
		{
			if (j >= 1)
				isprime[j - 1] = 0;
		}
		if (l == 1)
			isprime[0] = 0;
	}
}

void solve()
{
	int i;
	long long minn = INF, maxx = -INF;
	long long minl, minr, maxl, maxr;
	make_prime2();
	nprime2 = 0;
	for (int i = 0; i <= u - 1; i++)
	{
		if (isprime[i])
		{
			nprime2++;
			prime2[nprime2] = i + 1;
		}
	}
	if (nprime2 <= 1)
		printf("There are no agjust primes.\n");
	else
	{
		for (int i = 1; i < nprime2; i++)
		{
			if (prime2[i + 1] - prime2[i] < minn)
			{
				minn = prime2[i + 1] - prime2[i];
				minl = prime2[i];
				minr = prime2[i + 1];
			}
			if (prime2[i + 1] - prime2[i] > maxx)
			{
				maxx = prime2[i + 1] - prime2[i];
				maxl = prime2[i];
				maxr = prime2[i + 1];
			}
		}
		printf("XXXXXXXXXX\n");
	}
}

int main(void)
{
	make_prime1();
	while (scanf("%lld %lld", &l, &u) != EOF)
	{
		solve();
	}
	return 0;
}