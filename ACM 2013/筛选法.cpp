#include<stdio.h>
#include<math.h>
int a[100001];
int main()
{
	int i, j, n;
	while (scanf("%d", &n) == 1)
	{
		for (i = 2; i <= n; i++)
		{
			if (a[i] == 0)
				for (j = i + i; j <= n; j += i)
					a[j] = 1;
		}
		printf("2");
		for (i = 3; i <= n; i++)
			if (a[i] == 0)   
				printf(" %d", i);
		printf("\n");
	}
	return 0;
}
