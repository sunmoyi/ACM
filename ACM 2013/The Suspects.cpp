#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num[30005];
int rankk[30005];

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		num[i] = i;
		rankk[i] = 0;
	}
}

int find(int x)
{
	int far = x;
	while (far != num[far])
		far = num[far];

	int i = x;
	while (num[i] != far)
	{
		int temp = num[i];
		num[i] = far;
		i = temp;
	}
	return far;
}

void nuite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (rankk[x] < rankk[y])
		num[x] = y;
	else
	{
		num[y] = x;
		if (rankk[y] == rankk[x])
			rankk[x] ++;
	}
}

int main(void)
{
	int sum, n, m, k, head;
	while (scanf("%d %d", &n, &m) != EOF && (n + m))
	{
		sum = 0;
		init(n);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &k);
			scanf("%d", &head);
			for (int j = 2; j <= k; j++)
			{
				int tim;
				scanf("%d", &tim);
				nuite(tim, head);
			}
		}
		int bad = find(0);
		for (int i = 0; i < n; i++)
			if (find(i) == bad)
				sum++;
		printf("%d\n", sum);
	}
	return 0;
}