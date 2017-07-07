#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int prime[174387209];
int vis[174387209];
int phi[174387209];

void Prime(int n)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i<n; i++)
	{
		if (!vis[i])
		{
			prime[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j<cnt&&i*prime[j]<n; j++)
		{
			__int64 k = i*prime[j];
			vis[k] = 1;
			if (i%prime[j] == 0)
			{
				phi[k] = phi[i] * prime[j];
				break;
			}
			else
				phi[k] = phi[i] * (prime[j] - 1);

		}
	}
}

int main(void)
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		int ans = 0;
		int k = 874387202;
		Prime(k);
		for (int i = a; i <= b; i++)
		{
			ans += phi[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}

