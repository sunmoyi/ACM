#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;

int n, p[1000000];

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i]);

		if (n % 2 == 1)
			p[n++] = 0;
		sort(p, p + n);

		int x = 0;
		for (int i = 0; i < n - 1; i += 2)
			x ^= (p[i + 1] - p[i] - 1);

		if (!x)
			printf("Bob will win\n");
		else
			printf("Georgia will win\n");
	}
	return 0;
}