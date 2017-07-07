#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, a;
int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		int sum = 0, k = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d", &a);
			sum ^= a;
			if (a > 1)
				k = 1;
		}

		if (k)
		{
			if (sum)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
		{
			if (n % 2)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}