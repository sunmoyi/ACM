#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[10005][10];

int main(void)
{
	for (int i = 1; i < 10005; i++)
	{
		int k = i;
		for (int j = 0; j <= 9; j++)
			num[i][j] = num[i - 1][j];
		while (k > 0)
		{
			num[i][k % 10] = max(num[i][k % 10], num[i - 1][k % 10]) + 1;
			k /= 10;
		}
	}
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int m;
		scanf("%d", &m);
		for (int i = 0; i < 9; i++)
			printf("%d ", num[m][i]);
		printf("%d\n", num[m][9]);
	}
	return 0;
}