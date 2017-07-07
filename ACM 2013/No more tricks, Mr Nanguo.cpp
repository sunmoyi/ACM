#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#define maxn 4
#define M 8191

using namespace std;

typedef struct {
	int m[maxn][maxn];
}Matrax;
Matrax per, d;
int n, x, y, D;

void search()
{
	y = 1;
	while (1)
	{
		x = (long long)sqrt(D * y * y + 1);
		if (x * x - D * y * y == 1)
			break;
		y++;
	}
}

void init()
{
	d.m[0][0] = x % M;
	d.m[0][1] = D * y % M;
	d.m[1][0] = y % M;
	d.m[1][1] = x % M;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			per.m[i][j] = (i == j);
	}
}

Matrax multi(Matrax a, Matrax b)
{
	Matrax c;
	int k, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			c.m[i][j] = 0;
			for (k = 0; k < n; k++)
				c.m[i][j] += a.m[i][k] * b.m[k][j];
			c.m[i][j] %= M;
		}
	}
	return c;
}

Matrax power(int k)
{
	Matrax p, ans = per;
	p = d;
	while (k)
	{
		if (k & 1)
		{
			ans = multi(ans, p);
			k--;
		}
		k /= 2;
		p = multi(p, p);
	}
	return ans;
}

int main(void)
{
	int K;
	while (scanf("%d %d", &D, &K) != EOF)
	{
		int ad = sqrt(D + 0.0);
		if (ad * ad == D)
			printf("No answers can meet such conditions\n");
		else
		{
			search();
			n = 2;
			init();
			d = power(K - 1);
			x = (d.m[0][0] * x % M + d.m[0][1] * y % M) % M;
			printf("%d\n", x);
		}
	}
	return 0;
}