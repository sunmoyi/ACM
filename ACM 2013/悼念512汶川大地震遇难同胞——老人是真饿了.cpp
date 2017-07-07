#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, k;
struct ss{
	int price;
	int weight;
}a[100000];

bool cmp(ss a, ss b)
{
	return a.price < b.price;
}
int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		while (n--)
		{
			scanf_s("%d %d", &m, &k);
			memset(a, 0, sizeof(a));
			for (int i = 0; i < k; i++)
				scanf_s("%d %d", &a[i].price, &a[i].weight);
			sort(a, a + k, cmp);
			double sum = 0;
			for (int i = 0;m > 0;i++)
			{
				if (m >= a[i].price * a[i].weight)
				{
					m -= a[i].price * a[i].weight;
					sum += a[i].weight * 1.00;
				}
				else
				{
					double t = m * 1.00 / a[i].price;
					sum += t;
					m = 0;
				}
			}
			printf("%.2lf\n", sum);
		}
	}
	return 0;
}