#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[50050];
int T;
int sum;
char str[10];
int a, b;

int lowbit(int x)
{
	return x & (-x);
}

void add(int x, int y)
{
	while (x <= sum)
	{
		num[x] += y;
		x += lowbit(x);
	}
}

int summ(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += num[x];
		x -= lowbit(x);
	}
	return res;
}

int main(void)
{
	while (scanf_s("%d", &T) != EOF)
	{
		for(int ss = 1; ss <= T ; ss++)
		{
			memset(num, 0, sizeof(num));
			scanf_s("%d", &sum);
			for (int i = 1; i <= sum; i++)
			{
				scanf_s("%d", &a);
				add(i, a);
			}
			printf("Case %d:\n", ss);
			while (true)
			{
				getchar();
				scanf_s("%s", str, 6);
				if (str[0] == 'E')
					break;
				else if (str[0] == 'Q')
				{
					scanf_s("%d %d", &a, &b);
					int temp1 = summ(a - 1);
					int temp2 = summ(b);
					printf("%d\n", temp2 - temp1);
				}
				else if (str[0] == 'S')
				{
					scanf_s("%d %d", &a, &b);
					add(a, -b);
				}
				else
				{
					scanf_s("%d %d", &a, &b);
					add(a, b);
				}
			}
		}
	}
	return 0;
}