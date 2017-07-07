/*
˼������Է��ִ𰸾���
���Ѵ���+�ϲ�����-n-1 = ���Ѵ���*2-n-1��

��������������÷��Ѵ�����С��
���������򣬴�С��ͬ����������ͬһ�֣�
�� f[i][j] ��ʾ����i�����ӣ������������j�ѵ���С���Ѵ�����
ö����һ���������ڵĶ�k��
�����k���Է��ڵ�i-1�����ӵ�ĩβ�͵�i�����ӵĿ�ͷ��
��       f[i][j]=min(f[i-1][k]+ӵ�е�i�����ӵĶ���-1)��
����     f[i][j]=min(f[i-1][k]+ӵ�е�i�����ӵĶ���)��
��k��Ҫ�����������
���ǵ�k�Ѽ�ӵ�е�i�����ӣ�
��ӵ�е�i-1�����ӣ�
�ҳ��ǵ�i��������Դ����j������j!=k��
�𰸼�Ϊmin(f[m][i])(1<=i<=n)��
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2510

using namespace std;

pair<int, int>a[maxn];
int f[maxn][55];
int h[maxn][55];
int cnt[maxn];
int n, c, m;

void pre()
{
	int i, j, p;
	sort(a + 1, a + c + 1);
	c = unique(a + 1, a + c + 1) - a - 1;
	for (i = 1; i <= c; i++)
	{
		p = i;
		m++;
		while (a[p].first == a[p + 1].first && p < c)
			p++;
		for (j = i; j <= p; j++)
			h[m][a[j].second] = 1;
		cnt[m] = p - i + 1;
		i = p;
	}
}

int dp()
{
	int i, j, k, ans = 0x3f3f3f3f;
	memset(f, 127, sizeof(f));
	for (int i = 1; i <= n; i++)
		if (h[1][i])
			f[1][i] = cnt[1];
	for(i = 2; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (h[i][j])
			{
				for (k = 1; k <= n; k++)
				{
					if (h[i][k] && (cnt[i] == 1 || k != j))
						f[i][j] = min(f[i][j], f[i - 1][k] + cnt[i] - 1);
					else
						f[i][j] = min(f[i][j], f[i - 1][k] + cnt[i]);
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
		ans = min(ans, f[m][i]);
	return ans * 2 - n - 1;
}

int main(void)
{
	int i, j, k, t, test = 0;
	while (scanf("%d", &n) != EOF)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(h, 0, sizeof(h));
		m = c = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &t);
			for (int j = 1; j <= t; j++)
			{
				scanf("%d", &a[++c].first);
				a[c].second = i;
			}
		}
		pre();
		printf("Case %d: %d\n", ++test, dp());
	}
	return 0;
}