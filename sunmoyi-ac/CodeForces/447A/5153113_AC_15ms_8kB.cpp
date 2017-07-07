#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[305];
int goal[305];

int main(void)
{
	int p, n;
	while (scanf("%d %d", &p, &n) != EOF)
	{
		bool flag = true;
		int k;
		memset(goal, 0, sizeof(goal));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (goal[a[i] % p] == 1 && flag)
			{
				k = i;
				flag = false;
			}
			goal[a[i] % p]++;
		}
		if (flag)
			printf("-1\n");
		else
			printf("%d\n", k);
	}
	return 0;
}