#include<stdio.h>
#include<string.h>
int leicheng(int a, int b);
int main(void)
{
	char s[100];
	int i, j, k, l, n, m, len, a[10], sum, to[10];
	while (scanf_s("%s %d %d", s, &n, &m) != EOF)
	{
		len = strlen(s);
		for (i = 0; i < len; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				a[i] = s[i] - '0';
			else
				a[i] = s[i] - 55;
		}
		sum = 0;
		for (j = len - 1, l = 0; j >= 0; j--)
		{
			sum = sum + a[j] * leicheng(n, l);
			l++;
		}
		for (k = 0; k <= 10; k++)
		{
			to[k] = sum % m;
			sum = sum / m;
			if (sum == 0)
				break;
		}
		if (k > 7)
		{
			printf("   ERROR\n");
			continue;
		}
		for (l = 1; l <= 7 - k; l++)
			printf(" ");
		for (l = k; l >= 0; l--)
		{
			if (to[l] == 10)
				printf("A");
			else if (to[l] == 11)
				printf("B");
			else if (to[l] == 12)
				printf("C");
			else if (to[l] == 13)
				printf("D");
			else if (to[l] == 14)
				printf("E");
			else if (to[l] == 15)
				printf("F");
			else
				printf("%d", to[l]);
		}
		printf("\n");
	}
	return 0;
}
int leicheng(int a, int b)
{
	int t = 1;
	int i;
	if (b == 0)
		return 1;
	for (i = 1; i <= b; i++)
		t = t * a;
	return t;
}