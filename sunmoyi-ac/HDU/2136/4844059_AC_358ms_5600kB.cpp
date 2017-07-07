# include<stdio.h>
# define M 1000000
# include<string.h>
int prime[M];
int main()
{
	int n, i, j, k;
	memset(prime, 0, sizeof(prime));
	for (k = 1, i = 2; i < M; i++)
	{
		if (prime[i] == 0)
		{
			for (j = 1; i * j < M; j++)// 2是第一个素数 所以 2，4，6，8的最大素数位置应该为2
				prime[i * j] = k;// 但是6 = 2 * 3        3是比2大的素数所以在第一层for循环中会被后面
			k++;                 //覆盖，
		}                        // 总体思路：若i未在数组重赋值（未出现过计算）那么为它和它的倍数赋值k
	}                            //
	while (scanf_s("%d", &n) != EOF)
	{
		printf("%d\n", prime[n]);
	}
	return 0;
}
