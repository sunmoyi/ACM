#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sg[1 << 20];

void SG(int s)
{
	int k = 100;
	bool vis[21] = { 0 };
	for (int i = 19; i >= 0; i--)
	{
		if ((s >> i & 1) == 0)
			continue;
		bool flag = 0;
		if (k <= i - 1)
			vis[sg[s ^ (1 << i) ^ (1 << k)]] = 1;
		else
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if ((s >> j & 1) == 0)
				{
					k = j;
					vis[sg[s ^ (1 << i) ^ (1 << k)]] = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i <= 20; i++)
	{
		if (!vis[i])
		{
			sg[s] = i;
			break;
		}
	}
}

int main(void)
{
	for (int s = 0; s < (1 << 20); s++)
		SG(s);

	int t, n, m, a;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			int s = 0;
			while (m--)
			{
				scanf("%d", &a);
				s |= 1 << (20 - a);
			}
			res ^= sg[s];
		}
		if (res)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}