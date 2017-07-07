#include<cstdio>
#include<cstdlib>
#include<time.h>
#define maxn 100000

int main(void)
{
	printf("100000\n");
	srand((int)time(NULL));
	for (int i = 1; i < maxn; i++)
		printf("%d ", i);
	printf("%d\n", maxn);
	return 0;
}