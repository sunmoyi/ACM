#include<stdio.h>
void print_permutation(int n, int *A, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", A[i]);     // ��cur == nʱ�����е����ֵݹ���� ��� 
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{    //��������轫i����curλ�� ��������
			int ok = 1;
			for (int j = 0; j < cur; j++)
			{
				if (A[j] == i)
					ok = 0;
			}
			if (ok == 1)// ���ok = 1 ��ôû���ظ�
			{
				A[cur] = i;// ��i�������λ��
				print_permutation(n, A, cur + 1); //�ݹ�
			}

		}
	}
}