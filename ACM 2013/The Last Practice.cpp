#include<stdio.h>
#define maxn 65540
int a[maxn];
int ispriem(int a)
{
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0)
			return 0;
	return 1;

}
void cal(void)
{
	for (int i = 3; i <= maxn; i += 2)
	{
		if (ispriem(i))
			a[i] = 1;
	}
}
int main(void)
{
	int i, j, k, l, n, m, s, num;
	cal();
	a[2] = 1;
	k = 0;
	while (scanf_s("%d", &s) != EOF && s >= 0)
	{
		num = 0;
		if (k++)
			printf("\n");
		printf("Case %d.\n", k);
		if (a[s] == 1)
		{
			printf("%d 1 \n", s);
			continue;
		}
		else if (s % 2 == 0)
		{
			while (s % 2 == 0)
			{
				s /= 2;
				num++;
			}
			printf("2 %d ", num);
			for (i = 3; i <= s; i += 2)
			{
				num = 0;
				while (a[i] == 1 && s % i== 0)
				{
					s /= i;
					num++;
				}
				if (num)
					printf("%d %d ", i, num);
			}
			printf("\n");
		}
		else
		{
			for (i = 3; i <= s; i += 2)
			{
				num = 0;
				while (a[i] == 1 && s % i == 0)
				{
					s /= i;
					num++;
				}
				if (num)
				printf("%d %d ", i, num);
			}
			printf("\n");
		}
	}

}