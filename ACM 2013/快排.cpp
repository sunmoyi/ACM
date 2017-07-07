#include <stdio.h>
#include <stdlib.h> 

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
		swap(&list[m], &list[k]);
		key = list[m];
		i = m + 1;
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
		// 交换两个元素的位置
		swap(&list[m], &list[j]);
		// 递归地对较小的数据序列进行排序
		quicksort(list, m, j - 1);
		quicksort(list, j + 1, n);
	}
}

void printlist(int list[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", list[i]);
}

void main()
{
	const int MAX_ELEMENTS = 10;
	int list[MAX_ELEMENTS];

	int i = 0;

	// 产生填充序列的随机数
	for (i = 0; i < MAX_ELEMENTS; i++){
		list[i] = rand();
	}
	printf("进行排序之前的序列:\n");
	printlist(list, MAX_ELEMENTS);

	// sort the list using quicksort
	quicksort(list, 0, MAX_ELEMENTS - 1);

	// print the result
	printf("使用快速排序算法进行排序之后的序列:\n");
	printlist(list, MAX_ELEMENTS);
}