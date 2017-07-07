#include <stdio.h>
long long recursion(int a);
long long b[41][4];
int main (void)
{
	long long n, k;
	while(scanf("%d", &n) != EOF)
	{
		k = recursion(n);
		printf("%d\n", k);
	}
	return 0;
}
long long rucursion (int a)
{
	long long sum = 0;
	b[1][1] = 1;
	b[1][2] = 1;
	b[1][3] = 1;
	if(a > 1)
	{
		b[a][1] = b[a][3] =  recursion(a - 1);
		b[a][2] = b[a][3] - b[a - 1][2];
		sum = b[a][1] + b[a][2] + b[a][3];
	}
	else
		sum = 3;
	return sum;
}