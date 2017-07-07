#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct k{
	int price;
	int weight;
}a[105];
int v, m;

bool cmp(k a, k b)
{
	return a.price > b.price;
}
int main(void)
{
	while (scanf_s("%d", &v) != EOF && v)
	{
		scanf_s("%d", &m);
		memset(a, 0, sizeof(a));
		int sum = 0;
		for (int i = 1; i <= m; i++)
			scanf_s("%d %d", &a[i].price, &a[i].weight);
		sort(a + 1, a + m + 1, cmp);
		int i = 1;
		while (v)
		{
			if (v >= a[i].weight)
			{
				sum += a[i].price * a[i].weight;
				v -= a[i].weight;
			}
			else
			{
				sum += a[i].price * v;
				v = 0;
			}
			i++;
			if (i > m)
				break;
		}
		printf("%d\n", sum);
	}
	return 0;
}