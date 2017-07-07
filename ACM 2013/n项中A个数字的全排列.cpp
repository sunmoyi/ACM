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
		for (int i = 0; i < n; i++)//   此处为n个数字中有m个数字的全排列（n - m 为重复的个数）
			if (!i || p[i] != p[i - 1])// 此处IF是为了排除当初始序列P中含有多个相同的数值时重复计算
			{                         // 当然此处的前提是n个数字是完全排好序的       sort
				for (int j = 0; j < cur; j++)
					if (A[j] == p[i])
						c1++;
				for (int j = 0; j < n; j++)    // 此处上下c1, c2 代表的是在数列 a和p中某一个数字出现的次数  （主要是用来针对数列中存在重复数字的问题）
					if (p[i] == p[j])
						c2++;
				if (c1 < c2)//     如果C1小于c2 那么代表在p中还有可以供a调用的重复数字
				{
					A[cur] = p[i];//    赋值 下一步
					print_permutation(n, A, p, cur + 1);
				}
			}
	}
}