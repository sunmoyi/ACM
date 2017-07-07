#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int l, n, m;
int sum[500010];

bool fun(int k)
{
	int last = 0, front = 1, step = 0;//mark ÓÃfrontÇ°ÇýËÑË÷
	if (k * m < l)
		return false;
	while (front <= n + 1)
	{
		step++;
		if (sum[front] - sum[last] > k)
			return false;
		while (sum[front] - sum[last] <= k && front <= n + 1)
		{
			front++;//mark
		}
		last = front - 1;//mark
	}
	if (step > m)
		return false;
	return true;
}

int main(void)
{
	while (scanf_s("%d %d %d", &l, &n, &m) != EOF)
	{
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++)
		{
			scanf_s("%d", &sum[i]);
		}
		sum[n + 1] = l;

		sort(sum, sum + n + 2);

		int i = 0, u = l;
		while (i <= u)
		{
			int mid = (i + u) / 2;
			if (fun(mid))
				u = mid - 1;
			else
				i = mid + 1;
		}
		printf("%d\n", i);
	}
	return 0;
}

