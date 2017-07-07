#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
#include <time.h>  

int main()
{
	srand(time(NULL));
	int t, n = 5;
	while(n--)
	{
		int a, b;

		printf("%d %d\n", a = rand() % 200, b = rand() % 10);
		for (int i = 1; i <= b; i++)
		{
			printf("%d %d %d\n", (rand() % a), (rand() % a), rand() % 10000);
		}
		printf("%d %d\n", (rand() % a), (rand() % a));
		printf("\n");
	}
	return 0;
}