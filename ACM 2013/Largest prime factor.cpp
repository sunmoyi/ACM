# include<stdio.h>
# define M 1000000
# include<string.h>
int prime[M];
int main()
{
	int n, i, j, k;
	memset(prime, 0, sizeof(prime));
	for (k = 1, i = 2; i < M; i++)
	{
		if (prime[i] == 0)
		{
			for (j = 1; i * j < M; j++)// 2�ǵ�һ������ ���� 2��4��6��8���������λ��Ӧ��Ϊ2
				prime[i * j] = k;// ����6 = 2 * 3        3�Ǳ�2������������ڵ�һ��forѭ���лᱻ����
			k++;                 //���ǣ�
		}                        // ����˼·����iδ�������ظ�ֵ��δ���ֹ����㣩��ôΪ�������ı�����ֵk
	}                            //
	while (scanf_s("%d", &n) != EOF)
	{
		printf("%d\n", prime[n]);
	}
	return 0;
}

