#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[100000];
int len;

int main(void)
{
	int m;
	while (scanf("%d", &m) != EOF)
	{
		while (m--)
		{
			int n;
			memset(num, 0, sizeof(num));
			len = 0;
			scanf("%d", &n);
			if (n % 2 == 1)
				num[len++] = n;
			while (n != 1)
			{
				if (n % 2 == 1)
				{
					n = n * 3 + 1;
				}
				else
				{
					n /= 2;
				}
				if (n % 2 == 1 && n != 1)
					num[len++] = n;
			}
			if (len == 0)
				printf("No number can be output !\n");
			else
			{
				for (int i = 0; i < len - 1; i++)
					printf("%d ", num[i]);
				printf("%d\n", num[len - 1]);
			}
		}
	}
	return 0;
}