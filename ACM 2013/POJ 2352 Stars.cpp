#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 40000

using namespace std;

int c[maxn], level[maxn], n;

int lowbit(int  x)
{
	return x & (-x);
}

void add(int x)
{
	while (x <= maxn)
	{
		c[x] ++;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}

int main(void)
{
	int n, x, y;
	while (scanf("%d", &n) != EOF)
	{
		memset(level, 0, sizeof(level));
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			++x;
			add(x);
			level[sum(x)]++;
			//add(x);
		}
		for (int i = 1; i <= n; i++)
			printf("%d\n", level[i]);
	}
	return 0;
}