#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b;
	int i, j, m;
	printf("�������������µĽ�ѧ¥��ÿ�㴰��������¥����\n");
	scanf_s("%d%d", &i, &j);
	printf("����������λ�ڵ�¥��\n");
	scanf_s("%d", &m);
	i = 2 * i + 2;
	j = 2 * j + 1;
	m = j + 1 - 2 * m;
	for (a = 1; a <= j; a++)
	{
		if (i <= 1 || j <= 1 || m>j || m<2)
		{
			printf("�������Ǻ���ԭ��ģ��벻Ҫ����������ݵ�Ϸ��\n");
			break;
		}

		for (b = 1; b <= i; b++)
		{

			if (a == 1)
			{
				if (b == 1)
					printf("��");
				else if (b == 2)
					printf("-");
				else if (b != i)
					printf("--");
				else
					printf("��\n");
			}

			else if (a % 2 == 0 && a != j)
			{
				if (b == 1)
					printf("|");
				else if (b % 2 == 0 && b != i)
					printf("��");
				else if (b % 2 == 1 && b != i)
					printf("��");
				else
				{
					printf("|");
					if (a == m)
						printf("  �tO�s\n");
					else if (a == m + 2)
						printf("  /)\n");
					else printf("\n");
				}
			}

			else if (a % 2 == 1 && a != j)
			{
				if (b == 1) printf("|");
				else if (b % 2 == 0 && b != i)
					printf("��");
				else if (b % 2 == 1 && b != i)
					printf("��");
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
					printf("��");
			}
			else break;
		}
	}
	printf("��������������\n");
	printf("�����ѧ¥\nһԾ��ǧ��\n");
	getchar();
	system("pause");
	return 0;
}