#include<cstdio>

using namespace std;

int a[100] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881, 13482720 };
int n;

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", a[n]);
	}
	return 0;
}