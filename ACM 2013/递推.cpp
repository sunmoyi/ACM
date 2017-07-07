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
		swap(&list[m], &list[k]);// �������õ�ֵ�����ڴ�С������м�
		key = list[m];//    key�����滮������ı�׼
		i = m + 1;// list[m] �Ѿ�ȷ��Ϊ�����׼�������ж�
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
		// ���������ڵݹ鵽����ɶ�Ԫ�� ��һ�����𽻻���Ԫ��
		swap(&list[m], &list[j]);
		// �ݹ�ضԽ�С���������н�������
		quicksort(list, m, j - 1);// ��һ������������ֳ�2��С��  Ȼ��ݹ� ֱ���ֳ�һ��2Ԫ��
		quicksort(list, j + 1, n);
	}
}