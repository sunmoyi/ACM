# include <algorithm>
# include <string.h>
# include <stdio.h>
using namespace std;
int n, m;
int a[100010];
int judge(int x)
{
	int ans = 1;
	int tmp = 0;
	for (int i = 0; i<n; i++)
	{
		tmp += a[i];
		if (tmp>x)
		{
			tmp = a[i]; 
			ans++;
		}
	}
	if (ans <= m)
		return true;
	return false;
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int maxx = 0, sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			maxx = max(maxx, a[i]);
		}

		int l = maxx;
		int u = sum;
		while (l <= u)
		{
			int mid = (l + u) / 2;
			if (judge(mid))
				u = mid - 1;
			else
				l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}