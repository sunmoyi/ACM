#include<stdio.h>
#define maxn 32800
int a[maxn] ;
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
	int l, m, n;
	cal();
	a[2] = 1;
	while (scanf_s("%d", &n) != EOF && n != 0)
	{
		m = 0;
		for (l = 2; l <= n / 2; l++)
		{	
			if (a[l] == 1 && a[n - l] == 1)
				m++;
		}
		printf("%d\n", m);
	}
	return 0;
}