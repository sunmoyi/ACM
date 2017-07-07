#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1010

using namespace std;

struct node {
	int v;
	int k;
	int c;
	int l;
	bool friend operator < (const node&a, const node&b)
	{
		return a.v < b.v;
	}
}a[maxn];
int n, v1, k1, c1, l1;
int s[maxn];
int d[maxn];

int main(void)
{
	while (scanf("%d", &n) != EOF && n)
	{
		memset(s, 0, sizeof(s));
		memset(d, 0, sizeof(d));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
			scanf("%d %d %d %d", &a[i].v, &a[i].k, &a[i].c, &a[i].l);

		sort(a + 1, a + n + 1);

		s[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			s[i] = s[i - 1] + a[i].l;
		}

		d[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (j == 0)
					d[i] = s[i] * a[i].c + a[i].k;
				else
					d[i] = min(d[i], d[j] + (s[i] - s[j]) * a[i].c + a[i].k);
			}
		}

		printf("%d\n", d[n]);
	}
	return 0;
}