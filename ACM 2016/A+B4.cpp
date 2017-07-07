#include<stdio.h>

int main(void)
{
	int N, temp, sum;
	while (scanf("%d", &N) != EOF)
	{
		sum = 0;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
	}
	return 0;
}