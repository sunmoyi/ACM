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
			if(a[i] < m)//注意不能2边判断 因为可能输入的数字位于2侧
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
