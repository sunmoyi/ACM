#include<stdio.h>
int main(void)
{
	int a, b, c;
	while(scanf_s("%d", &a) != EOF);
	{
		if (a >= 20)
		{
			b = a / 10;
			c = a % 10;
			if (b == 2)
				printf("twenty");
			else if (b == 3)
				printf("thirty");
			else if (b == 4)
				printf("forty");
			else if (b == 5)
				printf("fifty");
			else if (b == 6)
				printf("sixty");
			else if (b == 7)
				printf("seventy");
			else if (b == 8)
				printf("eighty");
			else
				printf("ninety");

			if (c == 1)
				printf("-one\n");
			else if (c == 2)
				printf("-two\n");
			else if (c == 3)
				printf("-three\n");
			else if (c == 4)
				printf("-four\n");
			else if (c == 5)
				printf("-five\n");
			else if (c == 6)
				printf("-six\n");
			else if (c == 7)
				printf("-seven\n");
			else if (c == 8)
				printf("-eight\n");
			else if (c == 9)
				printf("-nine\n");
			else
				printf("\n");
		}
		else
		{
			if (a == 0)
				printf("zero\n");
			else if (a == 1)
				printf("one\n");
			else if (a == 2)
				printf("two\n");
			else if (a == 3)
				printf("three\n");
			else if (a == 4)
				printf("four\n");
			else if (a == 5)
				printf("five\n");
			else if (a == 6)
				printf("six\n");
			else if (a == 7)
				printf("seven\n");
			else if (a == 8)
				printf("eight\n");
			else if (a == 9)
				printf("nine\n");
			else if (a == 10)
				printf("ten\n");
			else if (a == 11)
				printf("eleven\n");
			else if (a == 12)
				printf("twelve\n");
			else if (a == 13)
				printf("thirteen\n");
			else if (a == 14)
				printf("fourteen\n");
			else if (a == 15)
				printf("fifteen\n");
			else if (a == 16)
				printf("sixteen\n");
			else if (a == 17)
				printf("seventeen\n");
			else if (a == 18)
				printf("eighteen\n");
			else
				printf("nineteen\n");

		}
	}
	return 0;
}