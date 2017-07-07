#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000100

using namespace std;

double sum[maxn];
int a[maxn];
int q[maxn];
int head, tail;

double getup(int i, int j)
{
	return sum[i] - sum[j];
}

double getdown(int i, int j)
{
	return i - j;
}

int main(void)
{
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		head = tail = 0;
		double ans = 0;
		q[tail++] = 0;

		for (int i = k; i <= n; i++)
		{
			while (head + 1 < tail &&
				getup(i, q[head]) * getdown(i, q[head + 1]) <=
				getup(i, q[head + 1]) * getdown(i, q[head]))
				head++;
			ans = max(ans, getup(i, q[head]) / getdown(i, q[head]));

			int j = i - k + 1;
			while (head + 1 < tail &&
				getup(j, q[tail - 1]) * getdown(q[tail - 1], q[tail - 2]) <=
				getup(q[tail - 1], q[tail - 2]) * getdown(j, q[tail - 1]))
				tail--;
			q[tail++] = j;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}