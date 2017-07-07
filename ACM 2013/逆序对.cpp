#include<stdio.h>
long long count = 0;
int a[1000000 + 5];
int b[1000000 + 5];
void Merge(int sourceArr[], int tempArr[], int starIndex, int midIndex, int endIndex)
{
	int i = starIndex;
	int j = midIndex + 1;
	int k = starIndex;

	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArr[i] < sourceArr[j])
			tempArr[k++] = sourceArr[i++];
		else
		{
			tempArr[k++] = sourceArr[j++];
			count += midIndex - i + 1;   // 与归并排序唯一增加的一条代码  算法竞赛入门经典 p226
		}
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];

	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
}

void Merge_sort(int sourceArr[], int tempArr[], int starIndex, int endIndex)
{
	int midIndex;
	if (starIndex < endIndex)
	{
		midIndex = (starIndex + endIndex) / 2;
		Merge_sort(sourceArr, tempArr, starIndex, midIndex);
		Merge_sort(sourceArr, tempArr, midIndex + 1, endIndex);
		Merge(sourceArr, tempArr, starIndex, midIndex, endIndex);

	}
}


int main(void)
{
	int t, i, k, min, temp;

	while (scanf_s("%d", &t) != EOF)
	{
		count = 0;
		getchar();
		for (i = 0; i < t; i++)
		{
			scanf_s("%d", &a[i]);
		}
		Merge_sort(a, b, 0,  t - 1);
		//min = count;
		//for (k = 0; k < t - 1; k++)
		//{
		//	count = 0;
		//	a[k + t] = a[k];
		//	Merge_sort(a, b, k + 1, k + t);
		//	if (count < min)
		//		min = count;
	//	}

		printf("%d\n", count);
	}
	return 0;
}
