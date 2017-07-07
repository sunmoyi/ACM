#include<cstdio>

using namespace std;

int main(void)
{
	int num;
	int a, b, c;
	while (scanf_s("%d", &num) != EOF)
	{
		a = num / 100;
		c = num % 10;
		b = (num % 100) / 10;

		//printf("%d %d %d", a, b, c);
		if (a * a * a + b * b *b + c * c *c == num)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}