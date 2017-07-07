#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num1[100010];
int num2[100010];
int num3[100010];
int n, m;

int main(void)
{
	int a, l, r;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
		memset(num3, 0, sizeof(num3));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			num1[i] = num1[i - 1];
			num2[i] = num2[i - 1];
			num3[i] = num3[i - 1];
			if (a == 1)
				num1[i]++;
			else if (a == 2)
				num2[i]++;
			else
				num3[i]++;
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &l, &r);
			printf("%d %d %d\n", num1[r] - num1[l - 1], num2[r] - num2[l - 1], num3[r] - num3[l - 1]);
		}
	}
	return 0;
}