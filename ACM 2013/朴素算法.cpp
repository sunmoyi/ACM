/*#include<stdio.h>
int main()
{
	int i, n;
	while (scanf_s("%d", &n) == 1)
	{
		for (i = 2; i < n; i++)
			if (n%i == 0)    
				break;
		if (i == n)    
			printf("YES\n");
		else          
			printf("NO\n");
	}
}*/
/*
ÓÅ»¯°æ±¾
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int i, n, x;
	while (scanf("%d", &n) == 1)
	{
		x = (int)sqrt((double)n);
		for (i = 2; i <= x; i++)
			if (n%i == 0)   
				break;
		if (i>x)    
			printf("YES\n");
		else          
			printf("NO\n");
	}
}
