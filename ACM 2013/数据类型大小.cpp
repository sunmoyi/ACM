# include <stdio.h>
int main (void)
{
	printf("char=%d\n",sizeof(char));
	printf("int=%d\n",sizeof(int));
	printf("short=%d\n",sizeof(short));
	printf("float=%d\n",sizeof(float));
	printf("double=%d\n",sizeof(double));
	printf("long=%d\n",sizeof(long));
	printf("long long=%d\n",sizeof(long long));
	printf("long double=%d\n",sizeof(long double));
	
	getchar();
	return 0;
}