#include<stdio.h>
#include<cmath>
int a[200001];
int main(void)        //      1�ĸ�����ȥ0 �ĸ�������ʣ��ĸ���       ���̺��ڣ�������������������������������������������������
{
	int n, i, sum0, sum1;
	while (scanf_s("%d", &n) != EOF)
	{
		sum1 = sum0 = 0;
		for (i = 1; i <= n; i++)
		{
			scanf_s("%1d", &a[i]);
		}
		for (i = 1; i <= n; i++)
		{
			if (a[i] == 1)
				sum1++;
			if (a[i] == 0)
				sum0++;
		}

		printf("%d\n", abs(sum1 - sum0));
	}
	return 0;
}