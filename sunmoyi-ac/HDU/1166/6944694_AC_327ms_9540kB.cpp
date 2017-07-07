#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000000

using namespace std;

int n, b[maxn], c[maxn];
char str[10];

int lowbit(int x)
{
	return x & (-x);
}

int sum2(int k)
{
	int ans = 0;
	while (k > 0)
	{
		ans += c[k];
		k -= lowbit(k);
	}
	return ans;
}

void add(int i, int x)
{
	while (i <= n)
	{
		c[i] += x;
		i += lowbit(i);
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int ss = 1; ss <= T; ss++)
	{
		scanf("%d", &n);
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		for (int k = 1; k <= n; k++)
			for (int l = k - lowbit(k) + 1; l <= k; l++)
				c[k] += b[l];
		printf("Case %d:\n", ss);
		getchar();
		scanf("%s", str);
		while (str[0] != 'E')
		{
			int change1, change2;
			scanf("%d %d", &change1, &change2);
			if (str[0] == 'Q')
				printf("%d\n", sum2(change2) - sum2(change1 - 1));
			else if (str[0] == 'A')
				add(change1, change2);
			else
				add(change1, -change2);
			getchar();
			scanf("%s", str);
		}
	}
	return 0;
}