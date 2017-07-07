#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
#define N 100005

int n;
int a[N], b[N];

struct node
{
	int i;   //num[k].i���k�ߵ�С�����ڶ��е�λ��
	int low;  //num[k].low ���k�ߵ�С���Ѻ����k�͵�С��������
	int high; //num[k].high���k�ߵ�С����ǰ���k�ߵ�С��������
}num[N];

int erfen(int *c, int k)  //����c�������׸���k��ȵ������±�
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
		for (i = 1; i <= n; i++)  //��a[]���±��
		{
			k = erfen(b, a[i]);
			a[i] = k;
			b[k]--;
			num[a[i]].i = i;
		}
		Merge(a, 1, n);  //�鲢������С���ѵ�high
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			k = num[i].i; //k��ʾ��i�͵�С�����ڶ��е�λ��
			w = i;  //w��ʾ�ǵ�w�͵�
			num[i].low = w - 1 - (k - 1 - num[i].high);
			t = num[i].high + num[i].low;
			ans += t*(t + 1) / 2;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
