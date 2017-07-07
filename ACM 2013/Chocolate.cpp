#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[105];
int n;

int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		int kkk = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d", &num[i]);
			if (num[i])
				kkk++;
		}

		int i = 1;
		while (num[i] != 1)
			i++;
		i++;
		long long sum = 1;
		int k = 0;
		for (; i <= n; i++)
		{
			if (num[i] == 1)
			{
				sum *= (k + 1);
				k = 0;
			}
			else
				k++;
		}
		if (kkk)
			printf("%lld\n", sum);
		else
			printf("0\n");
	}
	return 0;
}