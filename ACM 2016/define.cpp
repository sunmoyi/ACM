#include<stdio.h>
#define add  1+3
#define addd (1+3)

int main (void)
{
	printf("��������%d\n", 3 * add * 4);
	printf("������%d\n", 3 * addd * 4);
	return 0;
}