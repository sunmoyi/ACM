#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

struct k{
	char name[100];
	int price;
	int ml;
	double rate;
}a[10000];

bool cmp(k a, k b)
{
	if (a.rate != b.rate)
		return a.rate < b.rate;
	else
		return a.ml > b.ml;
}
int main(void)
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		while (T--)
		{
			int m;
			scanf("%d", &m);
			for (int i = 0; i < m; i++)
			{
				scanf("%s %d %d", a[i].name, &a[i].price, &a[i].ml);
				if (a[i].ml < 200)
				{
					a[i].rate = INT_MAX;
					getchar();
					continue;
				}
				int day = a[i].ml / 200;
				if (day > 5)
					day = 5;
				a[i].rate = a[i].price / day * 1.0;
				getchar();
			}
			sort(a, a + m, cmp);
			printf("%s\n", a[0].name);
		}
	}
	return 0;
}