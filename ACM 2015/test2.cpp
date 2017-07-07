#include <stdio.h>
void main()
{
	union
	{
		int a[2];
		long k;
		char c[4];
	}r, *s = &r;
	s->a[0] = 56;
	s->a[1] = 48;
	printf("%c\n", s->c[0]);
}
