#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int t;	
int n, k;
int a[100010];

bool find(int s)
{
	int l = 1, u = n;
	while (l <= u)
	{
		int mid = (l + u) / 2;
		if (a[mid] == s)
			return true;
		else if (a[mid] > s)
			u = mid - 1;
		else
			l = mid + 1;
	}
	return false;
}

int main(void)
{
	
	while (scanf_s("%d", &t) != EOF)
	{
		while (t--)
		{
			memset(a, 0, sizeof(a));
			scanf_s("%d %d", &n, &k);
			a[0] = -9999999999;
			for (int i = 1; i <= n; i++)
			{
				scanf_s("%d", &a[i]);
			}
			sort(a, a + n + 1);
			a[n] = INT_MAX;

			int sum = 0;
			for (int i = 1; a[i] <= k && i <= n; i++)
			{
				if (find(k - a[i]) && a[i - 1] != a[i])
					sum++;
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}