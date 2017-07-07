void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int choose_pivot(int i, int j)
{
	return((i + j) / 2);
}

void quicksort(int list[], int m, int n)
{
	int key, i, j, k;
	if (m < n)
	{
		k = choose_pivot(m, n);
		swap(&list[m], &list[k]);// 把区分用的值放置在大小数组的中间
		key = list[m];//    key是下面划分数组的标准
		i = m + 1;// list[m] 已经确定为分组标准不进行判断
		j = n;
		while (i <= j)
		{
			while ((i <= n) && (list[i] <= key))
				i++;
			while ((j >= m) && (list[j] > key))
				j--;
			if (i < j)
				swap(&list[i], &list[j]);
		}
		// 假设数组在递归到最后变成二元组 这一步负责交换二元组
		swap(&list[m], &list[j]);
		// 递归地对较小的数据序列进行排序
		quicksort(list, m, j - 1);// 将一个完整的数组分成2个小的  然后递归 直至分成一个2元组
		quicksort(list, j + 1, n);
	}
}