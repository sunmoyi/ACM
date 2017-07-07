#include <stdio.h>
#include <math.h>
int sushu(int a);
int main (void)
{
	int  n, i, flag1, flag2, flag;
	while(scanf_s("%d", &n) != EOF && n != 0)
	{
		flag = 0;
		for(i = 2; i < n/2; i++)
		{
			flag1 = sushu(i);
			flag2 = sushu(n - i);
			if(flag1 && flag2)
				flag = flag + 1;
		}
		printf("%d\n",flag);
	}
	return 0;
}
int sushu (int a)
{
	int i;
	for(i = 2; i <= sqrt((float)a); i++)
	{
		if(a % i == 0)
			return 0;
	}
	return 1;
}