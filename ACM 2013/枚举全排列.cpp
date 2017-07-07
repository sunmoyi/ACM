#include<stdio.h>
void print_permutation(int n, int *A, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", A[i]);     // 当cur == n时，所有的数字递归完毕 输出 
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{    //在这里假设将i放入cur位置 下文判重
			int ok = 1;
			for (int j = 0; j < cur; j++)
			{
				if (A[j] == i)
					ok = 0;
			}
			if (ok == 1)// 如果ok = 1 那么没有重复
			{
				A[cur] = i;// 将i放入出入位置
				print_permutation(n, A, cur + 1); //递归
			}

		}
	}
}