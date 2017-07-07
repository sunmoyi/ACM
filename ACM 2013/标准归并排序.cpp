#include<stdio.h>
#include<string.h>
int a[100000 + 5];
int b[100000 + 5];
void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArr[i] >= sourceArr[j])
			tempArr[k++] = sourceArr[i++];
		else
			tempArr[k++] = sourceArr[j++];
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}

//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = (startIndex + endIndex) / 2;
		MergeSort(sourceArr, tempArr, startIndex, midIndex);
		MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	}
}

int main(void)
{
	int t, i, k, min, n;
	while (scanf_s("%d", &n) != EOF)
	{
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i++)
			scanf_s("%d", &a[i]);
		MergeSort(a, b, 0, n - 1);
		for (i = 1; i <= n; i++)
			printf("%d ", a[i]);
	}
	return 0;
}
