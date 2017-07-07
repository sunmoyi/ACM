#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int a[maxn], l[maxn], r[maxn];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	l[1] = 1, r[n] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > a[i - 1])
			l[i] = l[i - 1] + 1;
		else
			l[i] = 1;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		if (a[i] < a[i + 1])
			r[i] = r[i + 1] + 1;
		else
			r[i] = 1;
	}
	int maxx = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i + 1] > a[i - 1] + 1)
		{
			if (l[i - 1] + 1 + r[i + 1] > maxx)
				maxx = l[i - 1] + 1 + r[i + 1];
		}
		else
		{
			if (l[i - 1] + 1 > maxx)
				maxx = l[i - 1] + 1;
			if (r[i + 1] + 1 > maxx)
				maxx = r[i + 1] + 1;
		}
	}
	printf("%d\n", maxx);
	return 0;
}