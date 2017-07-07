#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int pool[3005];
int k[3005];
int n, m;

int main(void)
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= m; i++)
			scanf("%d", &pool[i]);
		sort(pool + 1, pool + m + 1);
		for (int i = 2; i <= m; i++)
			k[i - 1] = pool[i] - pool[i - 1];
		int maxx = 0;
		int ss = 0;
		for (int i = 1; i < m; i++)
		{
			if (k[i] == 1)
			{
				ss++;
				maxx = max(maxx, ss);
			}
			else
			{
				ss = 0;
			}
		}
		if (pool[1] == 1 || pool[m] == n)
			printf("NO\n");
		else if (maxx >= 2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}