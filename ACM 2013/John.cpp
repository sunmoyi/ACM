#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t, n, a;

int main(void)
{
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			int sum = 0, k = 0;;
			scanf("%d", &n);
			for (int i = 1; i <= n; i++)
			{
				scanf("%d", &a);
				sum ^= a;
				if (a > 1)
					k = 1;
			}

			if (k)
			{
				if (sum > 0)
					printf("John\n");
				else
					printf("Brother\n");
			}
			else
			{
				if (n % 2)
					printf("Brother\n");
				else
					printf("John\n");

			}
		}
	}
}