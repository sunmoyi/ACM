#include<stdio.h>

int num[500], top;

int main()
{
	int Num;
	int index = 0;
	top = 0;
	scanf("%d", &Num);
	for (int i = 2; i <= Num; i++)
	{
		for (int n = 2; n<i; n++)
		{
			if (i%n == 0)
			{
				index = 1;
				break;
			}
		}
		if (index == 0)
			num[top++] = i;
		index = 0;
	}
	for (int i = 0; i < top - 1; i++)
		printf("%d ", num[i]);
	printf("%d\n", num[top - 1]);
	return 0;
}