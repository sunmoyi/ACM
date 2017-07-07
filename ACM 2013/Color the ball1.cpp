#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int c[maxn];
int n;

inline int lowbit(int x)
{
	return x & (-x);
}

inline void add(int i, int val)
{
	while (i <= n)
	{
		c[i] += val;
		i += lowbit(i);
	}
}

inline int sum(int i)
{
	int s = 0;
	while (i > 0)
	{
		s += c[i];
		i -= lowbit(i);
	}
	return s;
}

int main(void)
{
	int a, b;
	while (scanf_s("%d", &n) != EOF && n)
	{
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d %d", &a, &b);
			add(a, 1);
			add(b + 1, -1);
		}
		for (int i = 1; i < n; i++)
			printf("%d ", sum(i));
		printf("%d\n", sum(n));
	}
	return 0;
}