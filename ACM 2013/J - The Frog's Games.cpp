#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

int l, n, m, a[500005];

bool check(int x)
{
	int s = 0, count = 0, i = 0;
	if (x * m < l)
		return false;
	while (s < l)
	{
		s += x;
		while (a[i] <= s)
		{
			i++;
		}
		s = a[i - 1];
		count++;
	}
	if (count <= m)
		return true;
	else
		return false;
}

int dichotomie(int low, int high)
{
	int mid;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

int main(void)
{
	while (scanf("%d %d %d", &l, &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		a[n] = l;
		a[n + 1] = INT_MAX;
		int ans = a[0];
		for (int i = 1; i <= n; i++)
			if (a[i] - a[i - 1] > ans)
				ans = a[i] - a[i - 1];
		int fin = dichotomie(ans, l);
		printf("%d\n", fin);
	}
	return 0;
}