#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 101

using namespace std;

struct martax{
	int m[maxn][maxn];
}a, per;
int n, m;

void init()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d\n", &a.m[i][j]);
			a.m[i][j] %= m;
			per.m[i][j] = (i == j);
		}
	}
}

martax add(martax a, martax b)
{
	martax c;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			c.m[i][j] = (a.m[i][j] + b.m[i][j]) % m;
		}
	}
	return c;
}

martax multi(martax a, martax b)
{
	martax c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c.m[i][j] = 0;
			for (int k = 0; k < n; k++)
				c.m[i][j] += a.m[i][j] * b.m[i][j];
			c.m[i][j] %= m;
		}
	}
	return c;
}

martax power(int k)
{
	martax c, p, ans = per;
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

martax martaxsum(int k)
{
	if (k == 1)
		return a;
	martax temp, b;
	temp = martaxsum(k / 2);
	if (k & 1)
	{
		b = power(k / 2 + 1);
		temp = add(temp, multi(temp, b));
		temp = add(temp, b);
	}
	else
	{
		b = power(k / 2);
		temp = add(temp, multi(temp, b));
	}
	return temp;
}

int main(void)
{
	int k, i, j;
	while (scanf_s("%d %d %d", &n, &k, &m) != EOF)
	{
		init();
		martax ans = martaxsum(k);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n - 1; j++)
				printf("%d ", ans.m[i][j]);
			printf("%d\n", ans.m[i][j]);
		}
	}
	return 0;
}