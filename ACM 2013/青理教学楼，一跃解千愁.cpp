#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b;
	int i, j, m;
	printf("请输入您想跳下的教学楼的每层窗户数与总楼层数\n");
	scanf_s("%d%d", &i, &j);
	printf("请输入您想位于的楼层\n");
	scanf_s("%d", &m);
	i = 2 * i + 2;
	j = 2 * j + 1;
	m = j + 1 - 2 * m;
	for (a = 1; a <= j; a++)
	{
		if (i <= 1 || j <= 1 || m>j || m<2)
		{
			printf("本程序是很有原则的，请不要用无理的数据调戏我\n");
			break;
		}

		for (b = 1; b <= i; b++)
		{

			if (a == 1)
			{
				if (b == 1)
					printf("┌");
				else if (b == 2)
					printf("-");
				else if (b != i)
					printf("--");
				else
					printf("┐\n");
			}

			else if (a % 2 == 0 && a != j)
			{
				if (b == 1)
					printf("|");
				else if (b % 2 == 0 && b != i)
					printf("┌");
				else if (b % 2 == 1 && b != i)
					printf("┐");
				else
				{
					printf("|");
					if (a == m)
						printf("  ╰O╯\n");
					else if (a == m + 2)
						printf("  /)\n");
					else printf("\n");
				}
			}

			else if (a % 2 == 1 && a != j)
			{
				if (b == 1) printf("|");
				else if (b % 2 == 0 && b != i)
					printf("└");
				else if (b % 2 == 1 && b != i)
					printf("┘");
				else
				{
					printf("|");
					if (a == m + 1)
						printf("   /\n");
					else
						printf("\n");
				}
			}

			else if (a == j)
			{
				if (b <= i)
					printf("┴");
			}
			else break;
		}
	}
	printf("───────\n");
	printf("青理教学楼\n一跃解千愁\n");
	getchar();
	system("pause");
	return 0;
}