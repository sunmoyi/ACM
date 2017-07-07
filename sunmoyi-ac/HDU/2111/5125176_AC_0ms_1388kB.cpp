#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int p, n, pricee;
struct k{
	int price;
	int num;
}a[105];

bool cmp(k a, k b)
{
	return a.price > b.price;
}
int main(void)
{
	while (scanf("%d", &p) != EOF && p)
	{
		pricee = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &a[i].price, &a[i].num);
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (p > a[i].num)
			{
				p -= a[i].num;
				pricee += a[i].price * a[i].num;
			}
			else
			{
				pricee += a[i].price * p;
				break;
			}
		}
		printf("%d\n", pricee);
	}
	return 0;
}