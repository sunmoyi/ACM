#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int a[maxn];

int main(void)
{
	int n, m, d;
	while (scanf("%d %d %d", &n, &m, &d) != EOF)
	{
		for (int i = 0; i < n * m; i++)
			scanf("%d", &a[i]);
		sort(a, a + n * m);
		if (a[0] == a[n * m - 1])
			printf("0\n");
		else
		{
			int mid = a[n * m / 2];
			int flag, ans;
			flag = ans = 0;
			for (int i = 0; i < n * m; i++)
			{
				if (abs(a[i] - mid) % d)
				{
					flag = 1;
					break;
				}
				else
					ans += abs(a[i] - mid) / d;
			}
			if (flag)
				printf("-1\n");
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}