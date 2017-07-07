#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(void)
{
	char c;
	int i, j, k, l;
	scanf_s("%c", &c);
	if (isupper(c))
		printf("%c %d\n", tolower(c), c + 32);
	else if (islower(c))
		printf("%c %d\n", toupper(c), c - 32);
	else
		printf("%c %d\n", c, c);
	return 0;
}