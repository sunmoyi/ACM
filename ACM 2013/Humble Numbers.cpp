#include<stdio.h>  
int Min(int a, int b, int c, int d)
{
	int Min1 = a < b ? a : b;
	int Min2 = c < d ? c : d;
	return Min1 < Min2 ? Min1 : Min2;
}
int main()
{
	int n, a[5850], b2, b3, b5, b7;
	a[1] = 1;
	b2 = b3 = b5 = b7 = 1;
	int m = 1;
	while (m <= 5842)
	{
		int tmp = Min(2 * a[b2], 3 * a[b3], 5 * a[b5], 7 * a[b7]);
		a[++m] = tmp;
		if (tmp == 2 * a[b2]) b2++;
		if (tmp == 3 * a[b3]) b3++;
		if (tmp == 5 * a[b5]) b5++;
		if (tmp == 7 * a[b7]) b7++;
	}
	while (~scanf("%d", &n) && n)
	{
		printf("The %d", n);
		if (n % 10 == 1 && n % 100 != 11)
			printf("st");
		else if (n % 10 == 2 && n % 100 != 12)
			printf("nd");
		else if (n % 10 == 3 && n % 100 != 13)
			printf("rd");
		else
			printf("th");
		printf(" humble number is %d.\n", a[n]);
	}
	return 0;
}