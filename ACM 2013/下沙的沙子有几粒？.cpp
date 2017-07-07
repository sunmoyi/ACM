#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long num[25][25];
int n, m;

int main(void)
{
	for (int i = 0; i < 25; i++)
		num[i][0] = 1;
	for (int i = 1; i < 25; i++)//n
	{
		for (int j = i; j < 25; j++)//m
		{
			num[j][i] = num[j - 1][i] + num[j][i - 1];
		}
	}
	while (scanf("%d %d", &n, &m) != EOF)
	{
		printf("%lld\n", num[n][m]);
	}
	return 0;
}

