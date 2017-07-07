#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

double sum[maxn];
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
			scanf("%lf", &sum[i]);
			sum[i] += sum[i - 1];
		}
		head = tail = 0;
		q[tail++] = 0;
		double ans = 0;
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
		printf("%d\n", (int)(ans * 1000));
	}
	return 0;
}