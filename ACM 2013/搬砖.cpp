#include <stdio.h>
int res;
void fen(int x)
{
	if (x == 1)
	{
		return;
	}
	if (x % 2 == 1)
	{
		int num1 = x / 2;
		int num2 = x / 2 + 1;
		res++;
		fen(num1);
		fen(num2);
	}
	else
	{
		int num1 = x / 2;
		fen(num1);
		fen(num1);
	}
}
int main()
{
	int task;
	scanf("%d", &task);
	while (task--)
	{
		int num;
		res = 0;
		scanf("%d", &num);
		if (num == 0 || num == 1)
		{
			printf("0\n");
			continue;
		}
		if (num % 2 == 1)
		{
			int num1 = num / 2;
			int num2 = num / 2 + 1;
			res++;
			fen(num1);
			fen(num2);
		}
		else
		{
			int num1 = num / 2;
			fen(num1);
			fen(num1);
		}
		printf("%d\n", res);
	}
}
