#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1500

using namespace std;

int C[maxn][maxn];
int n, cmd;

int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int y, int s)
{
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			C[i][j] += s;
}

long long sum(int x, int y)
{
	long long sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			sum += C[i][j];
	return sum;
}

int main(void)
{
	int a, b, c, d;
	while (scanf("%d", &cmd) != EOF && cmd != 3)
	{
		if (cmd == 0)
		{
			scanf("%d", &n);
			memset(C, 0, sizeof(C));
		}
		else if (cmd == 1)
		{
			scanf("%d %d %d", &a, &b, &c);
			a++, b++;
			update(a, b, c);
		}
		else
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			a++, b++, c++, d++;
			printf("%lld\n", sum(c, d) - sum(c, b - 1) - sum(a - 1, d) + sum(a - 1, b - 1));
		}
	}
	return 0;
}