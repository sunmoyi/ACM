#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000010

using namespace std;

int a[maxn], b[maxn], n;

int bin(int len, int x)
{
	int mid, l, r;
	l = 1, r = len;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (x > b[mid])
			l = mid + 1;
		else if (x < b[mid])
			r = mid - 1;
		else
			return mid;
	}
	return l;
}

int LIS(void)
{
	int i, j;
	int len = 1;
	b[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		j = bin(len, a[i]);
		b[j] = a[i];
		len = max(len, j);
	}
	return len;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", LIS());
	return 0;
}