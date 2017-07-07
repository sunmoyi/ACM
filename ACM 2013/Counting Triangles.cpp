/*#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num1[505];
long long num2[505];
long long num3[505];
int n;

int main(void)
{
	for (int i = 1; i <= 502; i++)
	{
		num1[i] = i * i;
	}
	for (int i = 1; i <= 502; i++)
	{
		num2[i] = num2[i - 1] + i * (i - 1) / 2;
	}
	for (int i = 1; i <= 502; i++)
	{
		num3[i] = num2[i] + num1[i];
 	}
	while (scanf("%d", &n) != EOF)
	{
		printf("%lld\n", num1[n] + num2[n]);
	}
	return 0;
}*/


#include <stdio.h>

int main()
{
	int i, m, a[501] = { 0, 0 }, b[501] = { 0, 1 };
	m = 1;
	for (i = 2; i < 501; i++)
	{
		m += i;
		b[i] = b[i - 1] + m;
		a[i] = a[i - 2] + m - i;
	}
	while (~scanf("%d", &i))
		printf("%d\n", a[i] + b[i]);
	return 0;
}