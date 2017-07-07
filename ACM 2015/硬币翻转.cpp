#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char num[110];
int ans;

int main (void)
{
	while (scanf("%d", &ans) != EOF)
	{
		memset(num, false, sizeof(num));
		printf("%d\n", ans);
		for (int i = 1; i <= ans; i++)
		{
			for (int j = 1; j <= ans; j++)
			{
				if (i != j)
				{
					num[j] = !num[j];
				}
				if (num[j] == true)
					printf("1");
				else
					printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}
