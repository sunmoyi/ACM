#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
#define INF 0x3f3f3f3f

using namespace std;

int d[maxn], l[maxn], num[maxn], mark[maxn], sum[maxn], total[maxn];
int n;

struct node {
	int d, l;
	bool operator < (const node & b)
	{
		return l < b.l;
	}
}b[maxn];

int main(void)
{
	while (scanf("%d", &n) != EOF)
	{
		memset(num, 0, sizeof(num));
		memset(sum, 0, sizeof(sum));
		memset(total, 0, sizeof(total));
		memset(mark, 0, sizeof(mark));
		int low = INF, up = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &l[i]);
			low = min(low, l[i]);
			up = max(up, l[i]);
			b[i].l = l[i];
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &d[i]);
			b[i].d = d[i];
		}
		for (int i = 0; i < n; i++)
		{
			mark[l[i]]++;
			total[l[i]] += d[i];
		}
		for (int i = up; i >= low; i--)
		{
			sum[i] = sum[i + 1] + mark[i];
			total[i] += total[i + 1];
		}

		sort(b, b + n);
		int cnt = 0;
		int ans = INF;
		int temp;
		for (int i = low; i <= up; i++)
		{
			if (!mark[i])
				continue;
			while (cnt < n && b[cnt].l < i)
				num[b[cnt++].d]++;
			temp = total[i + 1];
			int p = n - sum[i];
			for (int j = 1; j <= 200 && p >= mark[i]; j++)
			{
				if (p - mark[i] + 1 < num[j])
				{
					temp += (p - mark[i] + 1) * j;
					p = -1;
				}
				else
				{
					temp += num[j] * j;
					p -= num[j];
				}
			}
			ans = min(ans, temp);
		}
		printf("%d\n", ans);
	}
	return 0;
}