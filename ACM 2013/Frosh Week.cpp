#include<stdio.h>  
#include<malloc.h>  
int ans;/////////////// 精度  
int a[1000000 + 50];
void merge(int left, int mid, int right)
{
	int i, j, cnt = 0;
	int *p;
	p = (int *)malloc((right - left + 1)*sizeof(int));
	i = left;
	j = mid + 1;
	while (i <= mid&&j <= right)//这时候i 和 j 指向的部分都排序完毕了 现在合并  
	{
		if (a[i] <= a[j])
		{
			p[cnt++] = a[i];
			i++;
		}
		else
		{
			p[cnt++] = a[j];
			j++;
			ans += mid - i + 1;//第i个比j大 由于i已经从小到大排过序了 那么i+1到mid的也会比j大  
		}
	}
	while (i <= mid)
	{
		p[cnt++] = a[i++];
	}
	while (j <= right)
	{
		p[cnt++] = a[j++];
	}
	cnt = 0;
	for (i = left; i <= right; i++)
		a[i] = p[cnt++];
	free(p);

}
void merge_sort(int left, int right)
{
	if (left<right) //长度大于1  这是个判断不是循环  
	{
		int mid;
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}
int main()
{
	int n, i;
	while (scanf_s("%d", &n) != EOF)
	{
		ans = 0;
		for (i = 0; i<n; i++)
			scanf_s("%d", &a[i]);
		merge_sort(0, n - 1);
		printf("%d\n", ans);//////////  
	}
	return 0;
}
