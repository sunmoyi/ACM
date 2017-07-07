#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
	long long a;
	long long b;
}sum[100005];
long long maxx;
long long n, m;

bool cmp(node c, node d)
{
	return c.a < d.a;
}

long long find(long long t)
{
	long long l = 0, u = n;
	while (l + 1< u)
	{
		long long mid = (l + u) / 2;
		if (sum[mid].a > t)
			u = mid;
		else
			l = mid;
	}
	return l;
}

int main(void)
{
	while (scanf_s("%lld %lld", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf_s("%lld %lld", &sum[i].a, &sum[i].b);

		sort(sum, sum + n, cmp);

		long long summ = 0;
		long long kkkk = 0;
		maxx = 0;
		long long kkk = find(sum[0].a + m - 1);
		for (int i = 0; i <= kkk; i++)
			maxx += sum[i].b;
		summ = maxx;
		for (int i = 1; i < n; i++)
		{
			summ -= sum[i - 1].b;
			kkkk = find(sum[i].a + m - 1);
			for (int j = kkk + 1; j <= kkkk; j++)
				summ += sum[j].b;
			if (summ > maxx)
				maxx = summ;
			kkk = kkkk;
		}
	
		printf("%lld\n", maxx);
	}
	return 0;
}