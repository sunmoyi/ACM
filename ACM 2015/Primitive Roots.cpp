#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int p;
	while (scanf("%d", &p) != EOF)
	{
		p -= 1;
		int re = p;
		for (int i = 2; i * i <= p; i++)
		{
			if (p % i == 0)
			{
				re = re - re / i;
				do {
					p /= i;
				} while (p % i == 0);
			}
		}
		if (p > 1)
			re = re - re / p;

		printf("%d\n", re);
	}
	return 0;
}