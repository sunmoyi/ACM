#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int a[10000005];
int s[10000005];

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}

		int ans = 1, step = 1;
		for (int i = 1; i <= n; i++)
		{
			while (a[i]--)
			{
				s[step] = ans;
				step++;
			}
			ans++;
		}
		scanf("%d", &m);
		int z;
		while (m--)
		{
			scanf("%d", &z);
			printf("%d\n", s[z]);
		}
	}
	return 0;
}