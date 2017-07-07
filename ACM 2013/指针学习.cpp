#include<stdio.h>
/*void swap_with_ptr(int *a, int *b)
{
	printf("%d %d\n", *a, *b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("%p\n%p\n", a, b);
	printf("%d %d", *a, *b);
	printf("\n\n\n\n\n\n");
}
int main(void)
{
	int x = 10;
	int y = 20;
	printf("%d %d\n", x, y);
	printf("%p\n%p\n", &x, &y);
	printf("\n\n\n\n\n\n");
	swap_with_ptr(&x, &y);
	printf("%d %d\n", x, y);
	printf("%p\n%p\n", &x, &y);
	return 0;
}*/
/*#include<string.h>
int strlen1(char *a);
int main(void)
{
	char str[1000] = "asfgfasguh eqkafdgvidsohgipthrjsugfdgsfiphbndfgbifgfdyieaodsipjfgnondutrfhvu";
	printf("%d\n", strlen1(str));
	return 0;
}
int strlen1(char *a)
{
	int len = strlen(a);
	if (len == 0)
		return -1;
	else
	{
		int start = 0, end = len - 1;
		while (start < end)
		{
			if (a[start] == ' ')
				return start;
			if (a[end] == ' ')
				return end;
			end++;
			start++;
		}
		return -1;
	}
}*/
