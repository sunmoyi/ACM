#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
#define N 100005

int n;
int a[N], b[N];

struct node
{
	int i;   //num[k].i存第k高的小朋友在队中的位置
	int low;  //num[k].low 存第k高的小朋友后面比k低的小朋友数量
	int high; //num[k].high存第k高的小朋友前面比k高的小朋友数量
}num[N];

int erfen(int *c, int k)  //返回c数组中首个和k相等的数的下标
{
	int l = 1, r = n, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (c[mid] == k)
		{
			if (c[mid - 1]<k)
				return mid;
			else
				r = mid - 1;
		}
		else if (c[mid]>k)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

void Merge(int *a, int l, int r)
{
	if (l == r) return;
	int i, j, k, mid;
	mid = (l + r) / 2;
	Merge(a, l, mid);
	Merge(a, mid + 1, r);
	for (i = l, j = mid + 1, k = 0; i <= mid && j <= r;)
	{
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else if (a[i] > a[j])
			b[k++] = a[j], num[a[j]].high += mid - i + 1, j++;
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= r)
		b[k++] = a[j++];
	for (i = l, j = 0; i <= r; i++)
		a[i] = b[j++];
}

int main()
{
	int i, k, w;
	long long ans, t;
	a[0] = -1;
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
			num[i].high = 0;
		for (i = 1; i <= n; i++)
		{
			scanf_s("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		for (i = 1; i <= n; i++)  //对a[]重新编号
		{
			k = erfen(b, a[i]);
			a[i] = k;
			b[k]--;
			num[a[i]].i = i;
		}
		Merge(a, 1, n);  //归并求所有小朋友的high
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			k = num[i].i; //k表示第i低的小朋友在队中的位置
			w = i;  //w表示是第w低的
			num[i].low = w - 1 - (k - 1 - num[i].high);
			t = num[i].high + num[i].low;
			ans += t*(t + 1) / 2;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
