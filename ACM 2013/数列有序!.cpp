# include <stdio.h>
int main (void)
{
	int  n, m, a[100], i, t;
	while(scanf("%d %d", &n, &m) == 2 && (n != 0 ||m != 0))
	{
		for(i = 0 ; i < n ;i++)
		{
			scanf("%d", &a[i]);
		}
		for(i = 0 ; i < n ;i++)
		{
			if(a[i] < m)//ע�ⲻ��2���ж� ��Ϊ�������������λ��2��
				t = i;
		}
		for(i = n ; i > t ; i--)
		{
			a[ i + 1 ] = a[i];
		}
		a[ t + 1 ] = m;
		for(i = 0 ; i < n ;i++)
			printf("%d ", a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}
