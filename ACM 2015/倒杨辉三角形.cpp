#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15

using namespace std;

int num[maxn][maxn];

int main(void)
{
	for (int i = 1; i < maxn; i++)
	{
		num[i][1] = 1;
		num[i][i] = 1;
	}
	for (int i = 2; i < maxn; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
		}
	}
	int a;
	while (scanf("%d", &a) != EOF)
	{
		for (int i = a; i >= 1; i--)
		{
			for (int j = 1; j <= a - i; j++)
				printf(" ");
			for (int j = 1; j < i; j++)
				printf("%d ", num[i][j]);
			printf("%d\n", num[i][i]);
		}
		printf("\n");
	}
	return 0;
}