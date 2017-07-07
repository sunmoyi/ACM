#include<cstdio>

int a, b;
int sum;
int ans;

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			sum = 1;
			scanf("%d %d", &a, &b);
			while (a != b)
			{
				if (a > b)
				{
					int temp = a;
					a = b;
					b = temp;
				}

				b -= a;
				++sum;
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}