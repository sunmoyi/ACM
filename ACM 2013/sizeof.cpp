# include<stdio.h>
int main (void)
{
	char a[8];
	char a2[8];
	char a3[8];
	scanf("%s", a);
	scanf("%s", a2);
	scanf("%s", a3);
	printf("%s\n%s\n%s", a, a2, a3);
	printf("%p %p %p", a, a2, a3);


	//printf("%d\n", sizeof(char));

	//char *p = a;

	//for (int i = 0; i < 16; ++i) {
		//putchar(*p);
		//p++;



	return 0;
}
