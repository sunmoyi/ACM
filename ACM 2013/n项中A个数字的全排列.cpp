#include<stdio.h>
void print_permutation(int n, int *A, int * p, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	else
	{
		int c1 = 0, c2 = 0;
		for (int i = 0; i < n; i++)//   �˴�Ϊn����������m�����ֵ�ȫ���У�n - m Ϊ�ظ��ĸ�����
			if (!i || p[i] != p[i - 1])// �˴�IF��Ϊ���ų�����ʼ����P�к��ж����ͬ����ֵʱ�ظ�����
			{                         // ��Ȼ�˴���ǰ����n����������ȫ�ź����       sort
				for (int j = 0; j < cur; j++)
					if (A[j] == p[i])
						c1++;
				for (int j = 0; j < n; j++)    // �˴�����c1, c2 ������������� a��p��ĳһ�����ֳ��ֵĴ���  ����Ҫ��������������д����ظ����ֵ����⣩
					if (p[i] == p[j])
						c2++;
				if (c1 < c2)//     ���C1С��c2 ��ô������p�л��п��Թ�a���õ��ظ�����
				{
					A[cur] = p[i];//    ��ֵ ��һ��
					print_permutation(n, A, p, cur + 1);
				}
			}
	}
}