#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream>  
#include<algorithm>
#define MAXN 10000

using namespace std;

int prime[MAXN + 1];
int nprime;
int e[MAXN + 1];

void getPrime() 
{
	int m = sqrt(MAXN + 0.5);
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= m; ++i)
		if (!prime[i])
			for (int j = i*i; j <= MAXN; j += i)
				prime[j] = 1;
	nprime = 0;
	for (int i = 2; i <= MAXN; ++i) 
	{
		if (!prime[i])
			prime[nprime++] = i;
	}
}

void add_integer(int n, int d) 
{
	for (int i = 0; i<nprime; i++) 
	{
		while (n%prime[i] == 0)
		{
			n /= prime[i];
			e[i] += d;
		}
		if (n == 1) 
			break;
	}
}
void add_factorial(int n, int d) 
{
	for (int i = 1; i <= n; i++)
		add_integer(i, d);
}
int main()
{
	getPrime();
	int p, q, r, s;
	while (scanf("%d%d%d%d", &p, &q, &r, &s) != EOF)
	{
		memset(e, 0, sizeof(e));
		add_factorial(p, 1);
		add_factorial(q, -1);
		add_factorial(p - q, -1);
		add_factorial(r, -1);
		add_factorial(s, 1);
		add_factorial(r - s, 1);
		int maxn = max(p, r);
		double ans = 1;
		for (int i = 0; i <= maxn; i++) 
			ans *= pow(prime[i], e[i]);
		
		printf("%.5lf\n", ans);
	}
	return 0;
}