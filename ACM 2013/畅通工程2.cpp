#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int par[1050];
int rankk[1050];
int a[1005];

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		par[i] = i;
		rankk[i] = 0;
	}
}

int find(int x)
{
	int far = x;
	while (far != par[far])
		far = par[far];

	int i = x;
	while (par[i] != far)
	{
		int temp = par[i];
		par[i] = far;
		i = temp;
	}
	return far;
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (rankk[x] < rankk[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if (rankk[y] == rankk[x])
			rankk[x]++;
	}
}

int main(void)
{
	int num, sum;
	while (scanf("%d", &num) != EOF && num)
	{
		scanf("%d", &sum);
		memset(a, 0, sizeof(a));
		init(num);

		for (int i = 1; i <= sum; i++)
		{
			int b, c;
			scanf("%d %d", &c,  &b);
			unite(c, b);
		}

		for (int i = 1; i <= num; i++)
			a[find(i)]++;

		int ans = 0;
		for (int i = 1; i <= num; i++)
			if (a[i])
				ans++;

		printf("%d\n", ans - 1);
	}
	return 0;
}