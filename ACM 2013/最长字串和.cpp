#include <stdio.h>  
int main()
{
	int n, T, a, sta, end, max, k, i, p, t;

	scanf("%d", &T);
	for (p = 1; p <= T; p++) {
		scanf("%d", &n);
		max = -9999;     //��Ϊһ����a ��-1000~1000�ģ����������൱�ڱ����Сֵ  
		t = 0;           //��ʾ ĳ��������  
		sta = end = k = 1;   // sta���͵Ŀ�ʼ,end���͵Ľ���,k��¼ÿ����͵Ŀ�ʼ  
		for (i = 1; i <= n; i++) 
		{
			scanf("%d", &a);

			t += a;
			if (t > max) 
			{   //��¼��������͵�ֵ  
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