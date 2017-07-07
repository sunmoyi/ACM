#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int n, m;
long long stone[maxn];
bool st[maxn];
int a, b, c, d;

int main(void)
{
	scanf("%d %d", &n, &m);
	st[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &stone[i]);
		int ans = 0;
		long long temp = stone[i] - 1;
		while (temp)
		{
			ans++;
			temp >>= 1;
		}
		if (ans % 2)
			st[i] = st[i - 1] + 1;
		else
			st[i] = st[i - 1];
	}
	while (m--)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a >= c && a <= d)
		{
			int temp = st[d] - st[c - 1];
			if ((stone[a] - 1) % 2 == (b - 1) % 2)
			{
				if (temp % 2)
					printf("daxia\n");
				else
					printf("suneast\n");
			}
			else
			{
				if((temp + 1) % 2)
					printf("daxia\n");
				else
					printf("suneast\n");
			}
		}
		else
		{
			int temp = st[d] - st[c - 1];
			if (temp % 2)
				printf("daxia\n");
			else
				printf("suneast\n");
		}
	}
	return 0;
}