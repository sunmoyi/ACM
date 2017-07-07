#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, x;
int a[10000000];

int find1(int t)
{
	int l = 0, u = n - 1;
	while (l + 1 < u)
	{
		int mid = (l + u) / 2;
		if (a[mid] >= t)
			u = mid;
		else
			l = mid;
	}
	return u;
}

int main(void)
{
	while (scanf("%d %d", &n, &x) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		int ans = find1(x);
		printf("%d\b", ans);
	}
	return 0;
}