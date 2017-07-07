#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int primer[65535 + 5];

int main(void)
{
	memset(primer, 0, sizeof(primer));

	for (int i = 2; i < 65535 / 2 + 2; i++)
	{
		for (int j = 2; i * j <= 65535 + 3; j++)
			primer[i * j] = 1;
	}
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (primer[n] == 0)
		{
			printf("%d\n", n);
			continue;
		}
		while (primer[n] != 0)
		{
			for (int i = 2; i < 65535 / 2 + 3; i++)
			{
				if (primer[i] == 0 && n % i == 0)
				{
					n /= i;
					printf("%d*", i);
					break;
				}
			}
		}
		printf("%d\n", n);
	}
	return 0;
}