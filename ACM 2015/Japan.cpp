#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500050

using namespace std;

long long c[maxn];
int n, m, k;

struct node {
	int u, v;
	bool friend operator < (const node&a, const node &b)
	{
		if (a.u != b.u)
			return a.u < b.u;
		return a.v < b.v;
	}
}arr[maxn];

inline int lowbit(int x)
{
	return x & (-x);
}

long long sum(int x)
{
	long long res = 0;
	while (x > 0)
	{
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}

void add(int x)
{
	while (x <= m)
	{
		c[x] ++;
		x += lowbit(x);
	}
}

int main(void)
{
	int T, casee = 1;
	scanf("%d", &T);
	while (T--)
	{
		printf("Test case %d: ", casee++);
		memset(c, 0, sizeof(c));

		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++)
			scanf("%d %d", &arr[i].u, &arr[i].v);

		sort(arr, arr + k);

		long long ans = 0;
		for (int i = 0; i < k; i++)
		{
			ans += sum(m) - sum(arr[i].v);
			add(arr[i].v);
		}
		printf("%lld\n", ans);
	}
	return 0;
}