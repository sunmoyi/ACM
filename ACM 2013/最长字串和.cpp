#include <stdio.h>  
int main()
{
	int n, T, a, sta, end, max, k, i, p, t;

	scanf("%d", &T);
	for (p = 1; p <= T; p++) {
		scanf("%d", &n);
		max = -9999;     //因为一个数a 是-1000~1000的，所以这里相当于变成最小值  
		t = 0;           //表示 某段连续和  
		sta = end = k = 1;   // sta最大和的开始,end最大和的结束,k记录每次求和的开始  
		for (i = 1; i <= n; i++) 
		{
			scanf("%d", &a);

			t += a;
			if (t > max) 
			{   //记录最大连续和的值  
				max = t;
				sta = k;
				end = i;
			}
			if (t < 0) 
			{
				t = 0;
				k = i + 1;
			}
		}

		if (p != 1) printf("/n");
		printf("Case %d:/n", p);
		printf("%d %d %d/n", max, sta, end);
	}
}