#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

long long sum;
long long p[maxn], pp[maxn], liu[maxn], xp[maxn];

int main(void)
{
	int n, t, l, r, m;
	while (scanf("%d", &n) != EOF)
	{
		p[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &liu[i]);
			xp[i] = liu[i];
			p[i] = p[i - 1] + liu[i];
		}
		xp[0] = 0;
		sort(xp, xp + n + 1);
		for (int i = 1; i <= n; i++)
			pp[i] = pp[i - 1] + xp[i];
		scanf("%d", &t);
		while(t--)
		{
			scanf("%d", &m);
			if (m == 1)
			{
				scanf("%d %d", &l, &r);
				sum = p[r] - p[l - 1];
				printf("%lld\n", sum);
			}
			else if (m == 2)
			{
				scanf("%d %d", &l, &r);
				sum = pp[r] - pp[l - 1];
				printf("%lld\n", sum);
			}
		}
	}
	return 0;
}