#include<cstdio>
#include<cmath>

using namespace std;

int main(void)
{
	int n, m;
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		int sum = 0;
		int a, b;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d %d", &a, &b);
			int num = abs(a - b) - 1;
			sum ^= num;
		}
		if (sum == 0)
			printf("BAD LUCK!\n");
		else
			printf("I WIN!\n");
	}
	return 0;
}