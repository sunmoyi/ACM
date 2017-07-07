#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000

using namespace std;

struct Martax {
	int m[maxn][maxn];
}a, pre;;

int n, M;

void init()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a.m[i][j]);
			a.m[i][j] %= M;
			pre.m[i][j] = (i == j);
		}
	}
}

Martax multi(Martax a, Martax b)
{
	Martax c;
	int k, i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			c.m[i][j] = 0;
			for (k = 0; k < n; k++)
				c.m[i][j] = a.m[i][k] * b.m[k][j];
			c.m[i][j] %= M;
		}
	}
	return c;
}

Martax power(int k)
{
	Martax c, p, ans = pre;
	p = a;
	while (k)
	{
		if (k & 1)
		{
			ans = multi(ans, p);
			k--;
		}
		else
		{
			k /= 2;
			p = multi(p, p);
		}
	}
	return ans;
}