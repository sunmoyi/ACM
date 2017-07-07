#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000000

using namespace std;

int num[maxn];
int n, m;

int main(void)
{
	int Case = 1;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		sort(num + 1, num + n + 1);
		printf("CASE# %d:\n", Case++);
		for (int i = 1; i <= m; i++)
		{
			int j = -1, k = -1, temp;
			scanf("%d", &temp);
			for (j = 1; j <= n; j++)
			{
				if (num[j] == temp)
				{
					k = j;
					break;
				}
			}
			if (k == -1)
				printf("%d not found\n", temp);
			else
				printf("%d found at %d\n", temp, k);
		}
	}
	return 0;
}