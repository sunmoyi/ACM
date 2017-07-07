#include<stdio.h>
int date[1005];
void init(int n)
{
	int i;
	for (i = 1; i <= n; i++)                  //初始情况的序列，1,2,3……n
		date[i] = i;
}
void find(int n, int m)
{
	int i, j, p, q, c1, c2, temp;
	for (i = 1; i <= m; i++)                //走m次找到第m个全排列情况             
	{
		for (j = n - 1; j >= 1; j--)
		{
			if (date[j] < date[j + 1])
			{
				c1 = j;                   //从序列右端开始找到“有选择项”的点并记录下来
				break;
			}
		}
		for (j = c1 + 1; j <= n; j++)
		{
			if (date[j] > date[c1])    //找到比“有选择项”的点的数字+1的数字，并记录下来
				c2 = j;
			else 
				break;
		}
		temp = date[c1];
		date[c1] = date[c2];           //交换
		date[c2] = temp;
		for (j = c1 + 1; j <= (c1 + 1 + n) / 2; j++)
		{
			q = n - (j - c1 - 1);
			temp = date[q];          //倒置
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