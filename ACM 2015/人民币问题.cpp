#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000

int num;
long long dp[maxn];

int main(void)
{
	while (scanf("%d", &num) != EOF)
	{
		num -= 8;
		int ans = 0;
		for (int i = 0; i * 5 <= num; i++)
		{
			for (int j = 0; j * 2 + i * 5 <= num; j++)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}