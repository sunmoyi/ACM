#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct k{
	int len;
	int wei;
}a[5005];

int b[5005];
int n, m;

bool cmp(k a, k b)
{
	if (a.len < b.len)
		return true;
	else if (a.len == b.len)
		return a.wei < b.wei;
	return false;
}
int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		while (n--)
		{
			memset(b, 0, sizeof(b));
			scanf_s("%d", &m);
			int i = 0;
			int t = m;
			while (t--)
			{
				scanf_s("%d %d", &a[i].len, &a[i].wei);
				i++;
			}
			sort(a, a + m, cmp);

			int ans = 0;

			for (int i = 0; i < m; i++)
			{
				if (!b[i])
				{
					b[i] = 1;
					ans++;
					int weight = a[i].wei;
					for (int j = i + 1; j < m; j++)
					{
						if (a[j].wei >= weight && !b[j])
						{
							b[j] = 1;
							weight = a[j].wei;
						}
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}