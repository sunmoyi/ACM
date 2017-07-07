#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct x{
	int j;
	int k;
	double rate;
}a[100000];

bool cmp(x &a, x &b)
{
	return a.rate > b.rate;
}
int main(void)
{
	int  n, sumc;
	double sum;
	while (scanf_s("%d %d", &sumc, &n) != EOF)
	{
		if (sumc == -1 && n == -1)
			break;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d %d", &a[i].j, &a[i].k);
			a[i].rate = a[i].j * 1.0 / a[i].k ;
		}
		sort(a, a + n, cmp);
		int ss = 0;
		while (sumc > 0 && ss < n)
		{
			if (a[ss].k < sumc)
			{
				sumc -= a[ss].k;
				sum += a[ss++].j;
			}
			else if (a[ss].k >= sumc)
			{
				double s = sumc * 1.0/ a[ss].k;
				sum += a[ss++].j * s;
				break;
			}
		}
		printf("%.3lf\n", sum);
	}
	return 0;
}