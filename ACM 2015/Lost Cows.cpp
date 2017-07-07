#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 8888

using namespace std;

int f[maxn];
int ar[maxn], flag[maxn];
int n;

int lowbit(int x)
{
	return x & (-x);
}

void add(int i)
{
	while (i <= n)
	{
		ar[i] += 1;
		i += lowbit(i);
	}
}

int sum(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += ar[x];
		x -= lowbit(x);
	}
	return res;
}

int query(int index)
{
	return index - sum(index);
}

int binary_search(int i, int l, int r)
{
	while (l < r)
	{
		int mid = (l + r) >> 1;
		int temp = query(mid);
		if (mid < i)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

int main(void)
{
	int i;
	scanf("%d", &n);
	for (i = 1; i < n; i++)
		scanf("%d", &f[i]);

	f[0] = 0;
	for (i = n - 1; i >= 0; i--)
	{
		int a = binary_search(f[i] + 1, 1, n);
		flag[i] = a;
		add(a);
	}
	for (i = 0; i < n; i++)
		printf("%d\n", flag[i]);
	return 0;
}