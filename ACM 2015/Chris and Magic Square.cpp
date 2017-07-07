#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long map[550][550];
int ans, x, y;

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		bool flag2 = false;
		for (int i = 1; i <= ans; i++)
			for (int j = 1; j <= ans; j++)
			{
				scanf("%lld", &map[i][j]);
				if (map[i][j] != 0)
					flag2 = true;
				if (map[i][j] == 0)
				{
					x = i;
					y = j;
				}
			}
		if (ans == 1)
		{
			printf("1\n");
			continue;
		}
		if (!flag2)
		{
			printf("0\n");
			continue;
		}
		long long sum = 0;
		bool flag = true;
		if (x != 1)
			for (int i = 1; i <= ans; i++)
				sum += map[1][i];
		else
			for (int i = 1; i <= ans; i++)
				sum += map[2][i];



		long long sum1 = 0;
		for (int i = 2; i <= ans; i++)
		{
			sum1 = 0;
			if (i != x)
				for (int j = 1; j <= ans; j++)
					sum1 += map[i][j];
			if (sum1 != 0 && sum1 != sum)
				flag = false;
		}
		sum1 = 0;
		for (int i = 1; i <= ans; i++)
		{
			sum1 = 0;
			if (i != y)
				for (int j = 1; j <= ans; j++)
					sum1 += map[j][i];
			if (sum1 != 0 && sum1 != sum)
				flag = false;
		}

		sum1 = 0;
		if (x != y)
		{
			for (int j = 1; j <= ans; j++)
				sum1 += map[j][j];
			if (sum1 != 0 && sum1 != sum)
				flag = false;
		}
		sum1 = 0;
		if (x + y != ans + 1)
		{
			for (int j = 1; j <= ans; j++)
				sum1 += map[j][ans - j + 1];
			if (sum1 != 0 && sum1 != sum)
				flag = false;
		}
		if (!flag)
		{
			printf("-1");
			continue;
		}





		long long num1, num2, num3, num4;
		num1 = sum;
		for (int i = 1; i <= ans; i++)
			if (i != y)
				num1 -= map[x][i];
		num2 = sum;
		for (int i = 1; i <= ans; i++)
			if (i != x)
				num2 -= map[i][y];
		num3 = num4 = num1;
		if (x == y)
		{
			num3 = sum;
			for (int i = 1; i <= ans; i++)
				if (i != x)
					num3 -= map[i][i];
		}
		if (x + y == ans + 1)
		{
			num4 = sum;
			for (int i = 1; i <= ans; i++)
				if (i != x)
					num4 -= map[i][ans - i + 1];
		}
		if (num1 == num2 && num2 == num3 && num3 == num4 && num1 > 0)
			printf("%lld\n", num1);
		else
			printf("-1\n");
	}
	return 0;
}