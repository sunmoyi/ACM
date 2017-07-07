#include<stdio.h>
int date[1005];
void init(int n)
{
	int i;
	for (i = 1; i <= n; i++)                  //��ʼ��������У�1,2,3����n
		date[i] = i;
}
void find(int n, int m)
{
	int i, j, p, q, c1, c2, temp;
	for (i = 1; i <= m; i++)                //��m���ҵ���m��ȫ�������             
	{
		for (j = n - 1; j >= 1; j--)
		{
			if (date[j] < date[j + 1])
			{
				c1 = j;                   //�������Ҷ˿�ʼ�ҵ�����ѡ����ĵ㲢��¼����
				break;
			}
		}
		for (j = c1 + 1; j <= n; j++)
		{
			if (date[j] > date[c1])    //�ҵ��ȡ���ѡ����ĵ������+1�����֣�����¼����
				c2 = j;
			else 
				break;
		}
		temp = date[c1];
		date[c1] = date[c2];           //����
		date[c2] = temp;
		for (j = c1 + 1; j <= (c1 + 1 + n) / 2; j++)
		{
			q = n - (j - c1 - 1);
			temp = date[q];          //����
			date[q] = date[j];
			date[j] = temp;
		}
	}
	return;
}
int main()
{
	int m, n;
	int i;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init(n);
		find(n, m - 1);
		for (i = 1; i <= n; i++)
		{
			if (i == 1)
				printf("%d", date[i]);
			else
				printf(" %d", date[i]);
		}
		printf("\n");

	}
	return 0;
}