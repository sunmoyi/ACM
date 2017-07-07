#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int q, r[50];

int gcd(int x, int y)
{
	if (x < y)
	{
		int temp = x;
		x = y;
		x = temp;
	}
	return y == 0 ? x : gcd(y, x % y);
}

void cal(int a, int m)
{
	r[0] = a % m;
	for (int i = 1; i < 32; i++)
		r[i] = (long long)r[i - 1] * r[i - 1] % m;
}
int cal(int m, int a, int b)
{
	int i = 0, j, k;
	int bl[32];
	while (b)
	{
		bl[i++] = b % 2;
		b >>= 1;
	}
	for (j = 0, k = 1; j < i; ++j)
		if (bl[j])
			k = (long long)k *r[j] % m;
	return k;
}

int main(void)
{
	int p, ca = 1;
	while (scanf("%d/%d", &p, &q) != EOF)
	{
		if (p == 0)
		{
			printf("Case #%d: 1,1\n", ca++);
			continue;
		}
		int gc = gcd(p, q);
		q /= gc;
		int x = 0;
		while (!(q & 1))
		{
			q >>= 1;
			x++;
		}
		x++;

		int pr[50][2], k = 0, p = q, rea = q;
		for (int i = 2; i * i <= p; i++)
		{
			if (p % i == 0)
			{
				rea = rea - rea / i;
				while (p % i == 0)
					p /= i;
			}
		}
		if (p > 1)
			rea = rea - rea / p;
		p = rea;
		for (int i = 2; i * i <= p; i++)
		{
			if (p % i == 0)
			{
				pr[k][0] = i;
				pr[k][1] = 0;
				while (p % i == 0)
				{
					pr[k][1]++;
					p /= i;
				}
				k++;
			}
		}
		if (p > 1)
		{
			pr[k][0] = p;
			pr[k][1] = 1;
			k++;
		}
		cal(2, q);
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < pr[i][1]; j++)
			{
				if (cal(q, 2, rea / pr[i][0]) != 1)
					break;
				rea /= pr[i][0];
			}
		}
		printf("Case #%d: %d,%d\n", ca++, x, rea);
	}
	return 0;
}