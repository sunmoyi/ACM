#include<cstdio>

using namespace std;

int main(void)
{
	int a, b;
	while (scanf_s("%d %d", &a, &b) != EOF)
	{
		if (a % (b + 1) == 0)
		{
			printf("none\n");
		}
		else if (a <= b)
		{
			for (int i = a; i < b; i++)
			{
				printf("%d ", i);
			}
			printf("%d\n", b);
		}
		else
			printf("%d\n", a % (b + 1));
	}
	return 0;
}